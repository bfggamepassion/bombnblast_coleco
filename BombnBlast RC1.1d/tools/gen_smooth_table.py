"""Génère smoothTable.c : les blocs virtuels du glissement horizontal des pièces.

Pour chaque paire de blocs voisins (G à gauche, D à droite ; 0 = vide, 1 = brique,
2 = bombe) et chaque décalage s (0, 2, 4 ou 6 pixels), on calcule le caractère vu
à travers une fenêtre de 8 pixels : les s premiers pixels viennent de la fin de G,
les 8-s suivants du début de D.

En mode 2 du TMS9918, chaque ligne de 8 pixels n'a que 2 couleurs. Quand le mélange
en demande 3, on garde le noir (la silhouette de la pièce sur le fond vide) et la
couleur la plus fréquente ; les autres pixels prennent la plus proche des deux.
Le défaut ne dure que les quelques images du glissement.

Les motifs des caractères 0 (vide), 1 (brique) et 2 (bombe) sont lus dans charset1.c
(ils sont identiques dans tous les jeux de caractères).

Usage : python gen_smooth_table.py   (depuis ce dossier ou n'importe où)
"""
import os
import re

HERE = os.path.dirname(os.path.abspath(__file__))
GAME = os.path.dirname(HERE)

# Palette TMS9918 (valeurs MAME), 0 = transparent affiché comme le fond noir
PALETTE = [(0, 0, 0), (0, 0, 0), (33, 200, 66), (94, 220, 120), (84, 85, 237), (125, 118, 252),
           (212, 82, 77), (66, 235, 245), (252, 85, 84), (255, 121, 120), (212, 193, 84),
           (230, 206, 128), (33, 176, 59), (201, 91, 186), (204, 204, 204), (255, 255, 255)]
BLACK = 1


def read_array(fn, name):
    t = open(fn, encoding='latin-1').read()
    m = re.search(r'const\s+byte\s+%s\[\]\s*=\s*\{(.*?)\};' % name, t, re.S)
    return [int(x, 0) for x in re.findall(r'0x[0-9A-Fa-f]+|\d+', m.group(1))]


def unrle(d):
    o = []
    i = 0
    while i < len(d):
        b = d[i]
        i += 1
        if b == 0xFF:
            break
        if b & 0x80:
            o += [d[i]] * ((b & 0x7F) + 1)
            i += 1
        else:
            o += d[i:i + b + 1]
            i += b + 1
    return o


def pixel_colors(pat, col):
    """Couleurs des 8 pixels d'une ligne (bit 7 = pixel de gauche)."""
    fg, bg = col >> 4, col & 15
    out = []
    for p in range(8):
        c = fg if pat & (0x80 >> p) else bg
        out.append(BLACK if c == 0 else c)
    return out


def dist(a, b):
    return sum((x - y) ** 2 for x, y in zip(PALETTE[a], PALETTE[b]))


def encode(pixels):
    """8 couleurs -> (motif, couleur) avec au plus 2 couleurs."""
    counts = {}
    for c in pixels:
        counts[c] = counts.get(c, 0) + 1
    kinds = sorted(counts, key=lambda c: (-counts[c], c))
    if len(kinds) == 1:
        return 0x00, (kinds[0] << 4) | kinds[0]
    if len(kinds) > 2:
        keep = [BLACK] if BLACK in counts else [kinds[0]]
        keep.append(next(c for c in kinds if c not in keep))
        pixels = [c if c in keep else min(keep, key=lambda k: dist(c, k)) for c in pixels]
        kinds = keep
    fg, bg = kinds[1], kinds[0]   # la couleur la moins fréquente en encre
    pat = 0
    for p, c in enumerate(pixels):
        if c == fg:
            pat |= 0x80 >> p
    return pat, (fg << 4) | bg


def main():
    cs = os.path.join(GAME, 'charset1.c')
    pats = unrle(read_array(cs, 'PATTERNRLE1'))
    cols = unrle(read_array(cs, 'COLORRLE1'))
    block = [(pats[c * 8:c * 8 + 8], cols[c * 8:c * 8 + 8]) for c in range(3)]

    table = []
    for left in range(3):
        for right in range(3):
            for s in range(4):
                sx = 2 * s
                if sx == 0:
                    table += block[right][0] + block[right][1]   # le bloc D tel quel
                    continue
                p_out, c_out = [], []
                for j in range(8):
                    lp = pixel_colors(block[left][0][j], block[left][1][j])
                    rp = pixel_colors(block[right][0][j], block[right][1][j])
                    p, c = encode(lp[8 - sx:] + rp[:8 - sx])
                    p_out.append(p)
                    c_out.append(c)
                table += p_out + c_out

    lines = ['/* Généré par tools/gen_smooth_table.py - ne pas modifier à la main */',
             '/* Blocs virtuels du glissement horizontal : index ((G*3+D)*4+s)*16,',
             '   G/D = bloc gauche/droite (0 vide, 1 brique, 2 bombe), s = décalage/2,',
             '   8 octets de motif puis 8 octets de couleur. */',
             '',
             '#include <coleco.h>',
             '',
             'const byte smoothTable[%d] = {' % len(table)]
    for k in range(0, len(table), 16):
        lr, s = divmod(k // 16, 4)
        sep = ',' if k + 16 < len(table) else ''
        lines.append('  ' + ', '.join('0x%02X' % x for x in table[k:k + 16]) + sep
                     + ' /* G=%d D=%d s=%d */' % (lr // 3, lr % 3, 2 * s))
    lines.append('};')
    out = os.path.join(GAME, 'smoothTable.c')
    open(out, 'w', encoding='latin-1', newline='\r\n').write('\n'.join(lines) + '\n')
    print('%s : %d octets' % (out, len(table)))


main()
