; smooth.s - Moteur d'affichage fluide de la piece du joueur
;            (chute verticale et glissement horizontal)
;
; Convention SDCC 3.0 : parametres sur la pile, l'appelant depile, IX preserve.
; Les boucles VRAM font au moins 37 T-states par octet : assez lent pour le
; TMS9918 meme pendant l'affichage.
; A appeler avec la NMI coupee (disable_nmi), comme le reste du code VRAM.
;
; Principe : chaque case ecran touchee par la piece recoit un caractere
; dynamique. Son contenu est la composition verticale (decalage dy) de deux
; "blocs virtuels" pris dans smoothTable : celui du haut et celui du bas,
; chacun etant le melange horizontal (decalage s) du bloc de gauche et du bloc
; de droite (voir tools/gen_smooth_table.py).
;
; Le rendu se fait en deux temps :
;  - smooth_prepare ecrit les caracteres dans la banque cachee (invisible a
;    l'ecran) et prepare la liste des ecritures de la table des noms
;  - smooth_commit applique cette liste (rapide, a faire pendant le retour de
;    trame pour qu'aucune partie de la piece n'ait une image de retard)
; Entre les deux, buf[] ne doit pas etre ecrase (pas de showBuffer).

	.module smooth

	.globl _smooth_prepare
	.globl _smooth_commit
	.globl _collide
	.globl _smoothPending
	.globl _smoothTable
	.globl _buf
	.globl _gameZone
	.globl _smoothN
	.globl _smoothCellOff

VDP_DATA = 0xBE
VDP_CTRL = 0xBF

COLTAB_H = 0x20		; octet haut de la table des couleurs (0x2000)
CHRTAB_W = 0x58		; octet haut ecriture table des noms affichee (0x1800|0x4000)
BUFTAB_W = 0x5C		; octet haut ecriture table des noms de travail (0x1C00|0x4000)

ZONEX    = 11		; GAMEZONESTARTX
ZONEW    = 10		; MAXXGAMEZONE
ZONEH    = 22		; MAXYGAMEZONE
MAXCELLS = 12		; SMOOTHMAX

; Zone de travail dans buf[] (buf n'est utilise ailleurs que par showBuffer)
;   _buf+0  : matrice 7x7 de la piece bordee de zeros, colonne par colonne,
;             puis numeros des blocs virtuels (gauche*3 + droite)
;   _buf+49 : liste d'ecritures pour smooth_commit : 3 octets par case
;             (decalage dans la table des noms lo/hi, caractere), 2*MAXCELLS max
; (pas d'equate sur _buf : le sdas de SDCC 3.0 genere alors de mauvaises relocations)

	.area _CODE

; Caracteres inutilises par tous les decors, le texte et les animations
smooth_banks:
	.db 24,25,26,27,28,29,30,31,33,34,35,36
	.db 37,38,39,40,45,46,47,59,60,61,62,63

; void smooth_prepare(byte *piece, byte bx, byte py, byte dy, byte s, byte bank)
;   piece : player.piece[rot], 25 octets ranges [x][y]
;   bx,py : case ecran du coin haut gauche de la matrice 5x5 (bx tient compte
;           du glissement : colonne de gauche si la piece arrive par la droite)
;   dy    : decalage vertical en pixels (0..7)
;   s     : decalage horizontal / 2 (0..3), vers la droite a partir de bx
;   bank  : banque de caracteres dynamiques (0/1), alternee a chaque rendu decale
_smooth_prepare:
	push	ix
	ld	ix,#0
	add	ix,sp
	; 4(ix),5(ix) = piece  6 = bx  7 = py  8 = dy  9 = s  10 = bank

	; --- Liste d'ecritures : d'abord les cases de la position affichee, qui
	;     retrouvent le contenu de la gameZone. Celles qui restent sous la piece
	;     seront reecrites ensuite, pendant le meme retour de trame.
	ld	hl,#_buf+49
	ld	(sm_wlp),hl
	xor	a
	ld	(sm_wln),a
	ld	a,(_smoothN)
	or	a
	jr	z,sp_rdone
	ld	b,a
	ld	hl,#_smoothCellOff
sp_rloop:
	push	bc
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	inc	hl
	push	hl
	ld	a,e			; colonne = decalage & 31
	and	#31
	sub	#ZONEX
	jr	c,sp_rskip
	cp	#ZONEW
	jr	nc,sp_rskip
	ld	c,a
	ld	a,e			; ligne = decalage >> 5
	rlca
	rlca
	rlca
	and	#7
	ld	b,a
	ld	a,d
	add	a,a
	add	a,a
	add	a,a
	or	b
	cp	#ZONEH
	jr	nc,sp_rskip
	ld	l,a			; gameZone[ligne*10 + colonne]
	ld	h,#0
	add	hl,hl
	push	de
	ld	d,h
	ld	e,l
	add	hl,hl
	add	hl,hl
	add	hl,de
	ld	e,c
	ld	d,#0
	add	hl,de
	ld	de,#_gameZone
	add	hl,de
	ld	a,(hl)
	pop	de
	call	wl_put
sp_rskip:
	pop	hl
	pop	bc
	djnz	sp_rloop
sp_rdone:

	; --- Matrice bordee : PM[(x+1)*7 + y+1] = piece[x][y], codes > 2 -> brique
	ld	hl,#_buf
	ld	(hl),#0
	ld	de,#_buf+1
	ld	bc,#48
	ldir
	ld	l,4 (ix)
	ld	h,5 (ix)
	ld	de,#_buf+8
	ld	c,#5
sp_mcol:
	ld	b,#5
sp_mrow:
	ld	a,(hl)
	inc	hl
	cp	#3
	jr	c,sp_mok
	ld	a,#1
sp_mok:
	ld	(de),a
	inc	de
	djnz	sp_mrow
	inc	de
	inc	de
	dec	c
	jr	nz,sp_mcol

	; --- Glissement : chaque colonne devient gauche*3 + droite (numero du bloc
	;     virtuel), calcule en place de la derniere colonne vers la premiere.
	;     Sans glissement, le numero est simplement le bloc lui-meme.
	ld	a,9 (ix)
	or	a
	jr	z,sp_nov
	ld	hl,#_buf+48
	ld	de,#_buf+41
	ld	b,#42
sp_vloop:
	ld	a,(de)
	ld	c,a
	add	a,a
	add	a,c
	add	a,(hl)
	ld	(hl),a
	dec	hl
	dec	de
	djnz	sp_vloop
sp_nov:

	; --- Banque, base de la table pour ce decalage horizontal (smoothTable + s*16)
	ld	hl,#smooth_banks
	ld	a,10 (ix)
	or	a
	jr	z,sp_bank0
	ld	hl,#smooth_banks+MAXCELLS
sp_bank0:
	ld	(sm_bankp),hl
	ld	a,9 (ix)
	add	a,a
	add	a,a
	add	a,a
	add	a,a
	ld	e,a
	ld	d,#0
	ld	hl,#_smoothTable
	add	hl,de
	ld	(sm_tbase),hl

	; --- Parcours des cases : colonnes pc = 1..6, lignes pr = 1..6.
	;     Case ecran (bx+pc-1, py+pr-1) : bloc virtuel du bas = V[pc][pr],
	;     du haut = V[pc][pr-1] (ignore si dy=0).
	xor	a
	ld	(sm_n),a
	ld	hl,#_buf+7
	ld	(sm_colp),hl
	inc	a
	ld	(sm_pc),a
sp_col:
	ld	hl,(sm_colp)		; colonne vide ?
	ld	b,#7
	xor	a
sp_orl:
	or	(hl)
	inc	hl
	djnz	sp_orl
	or	a
	jp	z,sp_colnext
	ld	a,#1
	ld	(sm_pr),a
sp_row:
	ld	hl,(sm_colp)
	ld	a,(sm_pr)
	ld	e,a
	ld	d,#0
	add	hl,de
	ld	a,(hl)
	ld	(sm_bot),a
	dec	hl
	ld	c,(hl)
	ld	a,8 (ix)
	or	a
	jr	nz,sp_hasdy
	ld	c,a
sp_hasdy:
	ld	a,c
	ld	(sm_top),a
	ld	hl,#sm_bot
	or	(hl)
	jp	z,sp_next		; case vide
	ld	a,(sm_n)
	cp	#MAXCELLS
	jp	nc,sp_next		; securite : ne peut pas arriver
	; decalage dans la table des noms = ligne*32 + colonne
	ld	a,(sm_pr)
	dec	a
	add	a,7 (ix)
	ld	(sm_line),a
	ld	l,a
	ld	h,#0
	add	hl,hl
	add	hl,hl
	add	hl,hl
	add	hl,hl
	add	hl,hl
	ld	a,(sm_pc)
	dec	a
	add	a,6 (ix)
	add	a,l
	ld	l,a			; colonne < 32 : pas de retenue
	ld	(sm_off),hl
	; ni decalage vertical ni horizontal : le caractere du bloc lui-meme
	ld	a,8 (ix)
	or	9 (ix)
	jr	nz,sp_comp
	ld	a,(sm_bot)
	jr	sp_store

sp_comp:
	; caractere de la banque, ecrit dans le tiers d'ecran de la case
	ld	hl,(sm_bankp)
	ld	a,(sm_n)
	ld	e,a
	ld	d,#0
	add	hl,de
	ld	a,(hl)
	ld	(sm_code),a
	ld	l,a
	ld	h,#0
	add	hl,hl
	add	hl,hl
	add	hl,hl
	ld	a,(sm_line)
	and	#0x18			; (ligne >> 3) << 3
	add	a,h
	ld	h,a
	ld	(sm_vaddr),hl
	ld	a,(sm_bot)
	call	vblock
	ld	(sm_hep),hl
	ld	a,(sm_top)
	call	vblock
	ld	(sm_abp),hl
	; motif
	ld	hl,(sm_vaddr)
	call	vsetw
	ld	hl,(sm_abp)
	ld	de,(sm_hep)
	call	upl8
	; couleur (8 octets plus loin dans les blocs virtuels)
	ld	hl,(sm_vaddr)
	ld	a,h
	add	a,#COLTAB_H
	ld	h,a
	call	vsetw
	ld	bc,#8
	ld	hl,(sm_hep)
	add	hl,bc
	ex	de,hl
	ld	hl,(sm_abp)
	add	hl,bc
	call	upl8
	ld	a,(sm_code)

sp_store:
	; a = caractere : liste d'ecritures et liste des cases affichees
	push	af
	ld	a,(sm_n)
	add	a,a
	ld	e,a
	ld	d,#0
	ld	hl,#_smoothCellOff
	add	hl,de
	ld	de,(sm_off)
	ld	(hl),e
	inc	hl
	ld	(hl),d
	pop	af
	call	wl_put
	ld	hl,#sm_n
	inc	(hl)

sp_next:
	ld	hl,#sm_pr
	inc	(hl)
	ld	a,(hl)
	cp	#7
	jp	c,sp_row
sp_colnext:
	ld	hl,(sm_colp)
	ld	de,#7
	add	hl,de
	ld	(sm_colp),hl
	ld	hl,#sm_pc
	inc	(hl)
	ld	a,(hl)
	cp	#7
	jp	c,sp_col

	ld	a,(sm_n)
	ld	(_smoothN),a
	ld	a,#1
	ld	(_smoothPending),a
	pop	ix
	ret

; void smooth_commit(void)
; Applique la liste d'ecritures aux deux tables des noms.
_smooth_commit:
	ld	a,(_smoothPending)
	or	a
	ret	z
	xor	a
	ld	(_smoothPending),a
	ld	a,(sm_wln)
	or	a
	ret	z
	ld	b,a
	ld	hl,#_buf+49
	ld	c,#VDP_CTRL
sc_loop:
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	inc	hl
	out	(c),e
	ld	a,d
	add	a,#CHRTAB_W
	out	(c),a
	ld	a,(hl)
	out	(VDP_DATA),a
	out	(c),e
	ld	a,d
	add	a,#BUFTAB_W
	out	(c),a
	ld	a,(hl)
	out	(VDP_DATA),a
	inc	hl
	djnz	sc_loop
	ret

; char collide(byte *piece, char lig, char col)
; Meme regle que checkCollide : NOK (1) si un bloc de la piece (rangee [x][y])
; sort de la zone de jeu ou tombe sur une case non vide de la gameZone.
_collide:
	push	ix
	ld	ix,#0
	add	ix,sp
	; 4(ix),5(ix) = piece  6 = lig  7 = col
	ld	l,4 (ix)
	ld	h,5 (ix)
	ld	c,#0
cc_col:
	ld	b,#0
cc_row:
	ld	a,(hl)
	or	a
	jr	z,cc_next
	ld	a,7 (ix)
	add	a,c
	cp	#ZONEW			; non signe : une colonne negative est >= 0x80
	jr	nc,cc_hit
	ld	e,a
	ld	a,6 (ix)
	add	a,b
	cp	#ZONEH
	jr	nc,cc_hit
	push	hl
	push	bc
	ld	l,a
	ld	h,#0
	add	hl,hl
	ld	b,h
	ld	c,l
	add	hl,hl
	add	hl,hl
	add	hl,bc
	ld	d,#0
	add	hl,de
	ld	bc,#_gameZone
	add	hl,bc
	ld	a,(hl)
	pop	bc
	pop	hl
	or	a
	jr	nz,cc_hit
cc_next:
	inc	hl
	inc	b
	ld	a,b
	cp	#5
	jr	c,cc_row
	inc	c
	ld	a,c
	cp	#5
	jr	c,cc_col
	ld	l,#0
	pop	ix
	ret
cc_hit:
	ld	l,#1
	pop	ix
	ret

; Ajoute (de = decalage dans la table des noms, a = caractere) a la liste
wl_put:
	ld	hl,(sm_wlp)
	ld	(hl),e
	inc	hl
	ld	(hl),d
	inc	hl
	ld	(hl),a
	inc	hl
	ld	(sm_wlp),hl
	ld	hl,#sm_wln
	inc	(hl)
	ret

; hl = smoothTable + a*64 + s*16   (a = bloc virtuel = gauche*3 + droite)
vblock:
	ld	l,a
	ld	h,#0
	add	hl,hl
	add	hl,hl
	add	hl,hl
	add	hl,hl
	add	hl,hl
	add	hl,hl
	ld	de,(sm_tbase)
	add	hl,de
	ret

; Adresse VRAM hl en ecriture
vsetw:
	ld	a,l
	out	(VDP_CTRL),a
	ld	a,h
	and	#0x3F
	or	#0x40
	out	(VDP_CTRL),a
	ret

; Envoie 8 lignes vues a travers une fenetre decalee de dy lignes :
;   lignes 8-dy..7 du bloc du haut (hl), puis lignes 0..7-dy du bloc du bas (de)
upl8:
	ld	c,#VDP_DATA
	ld	a,8 (ix)
	or	a
	jr	z,upl_bot
	ld	b,a
	ld	a,#8
	sub	b
	add	a,l
	ld	l,a
	jr	nc,upl_top
	inc	h
upl_top:
	ld	a,(hl)
	out	(c),a
	inc	hl
	djnz	upl_top
upl_bot:
	ex	de,hl
	ld	a,#8
	sub	8 (ix)
	ld	b,a
upl_b:
	ld	a,(hl)
	out	(c),a
	inc	hl
	djnz	upl_b
	ret

	.area _DATA
sm_bankp:	.ds 2
sm_tbase:	.ds 2
sm_wlp:		.ds 2
sm_colp:	.ds 2
sm_off:		.ds 2
sm_vaddr:	.ds 2
sm_abp:		.ds 2
sm_hep:		.ds 2
sm_n:		.ds 1
sm_pc:		.ds 1
sm_pr:		.ds 1
sm_top:		.ds 1
sm_bot:		.ds 1
sm_code:	.ds 1
sm_line:	.ds 1
sm_wln:		.ds 1
_smoothPending:	.ds 1
