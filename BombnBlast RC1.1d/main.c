#include <string.h>
#include <coleco.h>
#include <getput1.h>

/*
	RENDERLIGNEPLEINE
	1.0 - Trouver les lignes pleines - Animation - = DETECT
	
	DETECT
	2.0 - Marquer les bombes à faire péter en premier (Code BOMBMARQUE pour normal,MEGABOMBMARQUE pour MegaBomb) workflow = EXPLODE1
	
	EXPLODE1
	2.5 - Faire péter les bombes marquées (Animation) 
	
	EXPLODE2
	supprimer les briques (code DETRUIT, pas VIDE) et les bombes péter , en profiter
		pour marquer les nouvelles à péter (Code BOMBMARQUEPASS2 pour normal,MEGABOMBMARQUEPASS2 pour megabomb,)  A la fin de l'anim workflow = EXPLODE3
	
	EXPLODE3
	3.5 - Repasse ces codes BOMBMARQUEPASS2 et MEGABOMBMARQUEPASS2 à BOMBMARQUE et MEGABOMBMARQUE et remplit la table  des  lignes
		oui il y à des bombes à péter workflow = EXPLODE1 (si il y à encore des bombes) sinon workflow = REDUCE
	
	REDUCE --> Algo précis à trouver !! (Se baser sur la plus basse ligne pétée ou le code DETRUIT)
	En gros si on est sur un code DETRUIT et au dessus il y à une brique on la descend et on met DETRUIT à la place
	Si il n'y à plus rien à descendre on passe les DETRUIT à VIDE 
	4.0 - Réduit la zone de jeu / rendu / Si il y encore à réduire worklow = REDUCE sinon 
		mise à 0 de la table de détection des lignes workflow = INGAME
	
	
	
	*/

#define NO_SPRITES
#define chrtab  0x1800 /* écran en linéaire */
#define chrgen  0x0000 /* table des caractères */
#define coltab  0x2000 /* couleur des caractères */
#define sprtab  0x3800 /* sprite_pattern_table */
#define sprgen  0x1b00 /* sprite_attribute_table */
#define buffer  0x1c00 /* buffer screen 2 */

#define HORAIRE 1
#define ANTIHORAIRE 2

#define INIT 1
#define REINIT 2

#define MAXX	32
#define MAXY	24

#define OK          0
#define NOK         1

#define ON 1
#define OFF 0


#define DOWNTIMER 30

#define MAXXGAMEZONE	10
#define MAXYGAMEZONE	22
/* MAXY, tester à 18 ou 20 pour pouvoir mettre un fond!! */

#define GAMEZONESTARTX 11
#define GAMEZONESTARTY 0

#define TYPE1 1
#define TYPE2 2

#define PLAYERSTARTX 2
#define TOUCHEDELAI  5

#define MENU 8
#define INGAME	   0
#define RENDERLIGNEPLEINE 1
#define DETECT 2
#define EXPLODE1 3
#define EXPLODE2 4
#define EXPLODE3 5
#define REDUCE 6
#define GAMEOVER 7
#define NEXTLEVEL 9



#define VIDE 0
#define BRIQUE 1
#define BOMB 2
#define MEGABOMBCODE1 14
#define MEGABOMBCODE2 22
#define MEGABOMBCODE3 15
#define MEGABOMBCODE4 23

#define BOMBMARQUE 41
#define MEGABOMBMARQUE 42
#define BOMBMARQUEPASS2 43
#define MEGABOMBMARQUEPASS2 44

/*
#define DETRUIT 45
*/
#define DETRUIT 18


#define CHARBLAST 158 // A voir si on peut faire mieux.


static const byte yellow_font[8]= { 0xa1,0xb1,0xe1,0xf1,0xe1,0xb1,0xa1,0xa1};
static const byte bleuclair_font[8]= { 0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07};
static const byte bleumoyen_font[8]= { 0xa5,0xb5,0xe5,0xf5,0xe5,0xb5,0xa5,0xa5};
static const byte bleufonce_font[8]= { 0xa4,0xb4,0xe4,0xf4,0xe4,0xb4,0xa4,0xa4};

static const byte vide[25] = {
								0,0,0,0,0,
								0,0,0,0,0,
								0,0,0,0,0,
								0,0,0,0,0,
								0,0,0,0,0};


extern const byte NAMERLE_TITLE[];
extern const byte PATTERNRLE_TITLE[];
extern const byte COLORRLE_TITLE[];

extern const byte NAMERLE1[];
extern const byte PATTERNRLE1[];
extern const byte COLORRLE1[];

extern const byte NAMERLE2[];
extern const byte PATTERNRLE2[];
extern const byte COLORRLE2[];

extern const byte NAMERLE3[];
extern const byte PATTERNRLE3[];
extern const byte COLORRLE3[];

extern const byte NAMERLE4_1[];
extern const byte NAMERLE4_2[];
extern const byte PATTERNRLE4[];
extern const byte COLORRLE4[];

extern byte* levels[];


/* from music.s */
extern const void explosion[];
extern const void music[];

/* from sound.s */
extern const void snd_table[];

char workflow;
char currentLevel;
char maxRandom;

char cheat; // variable permettant de simplifier le jeu
char endGame;

struct p	
{
	char x,y; // Position x,y dans l'écran
	char oldx,oldy; // Ancienne position x,y dans l'écran
	
	char lig,col; // Position x,y dans la gameZone
	char oldLig,oldCol; // Ancienne position x,y dans la gameZone
	
	char codePiece; // Code de début de rotation de la pièce
	// Ex : 0 = Pièce 0
	//	4 = Pièce 1 etc etc ...
	char nextCodePiece;
	
	char piece[4][5][5];  // Stockage de la piece (rotation, x,y)
	char nextPiece[25];
	byte randomBombe;
	byte nextRandomBombe;
	
	char rot; // Rotation courante
	char oldRot; // Ancienne rotation
	char pieceRestante;
	
	unsigned timer;
	
	unsigned score;
	


} player;

char downTimer;
char currentDownTimer;

char delaiToucheGauche;
char delaiToucheDroite;
char delaiToucheFire1;
char blastRadius;

char gameZone[MAXXGAMEZONE*MAXYGAMEZONE];
char lignePleineGameZone[MAXYGAMEZONE];

extern const char pieceData[22*4][25]; // 28 Pièces de 4 rotations - 1 pièce = 5*5

char doRenderPlayer;
char doRenderNextPiece;
char doRenderGameZone;
char doRenderExplosion;

char difficulte;
char typectrl;

byte buf[256];
	
void playExplosion(void)
{
	stop_sound(4);
	stop_sound(5);
	play_sound(4);
	play_sound(5);
}

void showBuffer()
{
	unsigned offsety;
	offsety = 0;
	
	get_vram(buffer+offsety,buf,256);
	put_vram(chrtab+offsety,buf,256);
	offsety+=256;
	get_vram(buffer+offsety,buf,256);
	put_vram(chrtab+offsety,buf,256);
	offsety+=256;
	get_vram(buffer+offsety,buf,256);
	put_vram(chrtab+offsety,buf,256);	
}

void copyLevel2GameZone()
{
	byte nb,val,i,j,k;
	byte *offset;
	
	nb=0;val=0;i=0;j=0;k=0;
	
	currentDownTimer = DOWNTIMER - currentLevel;
	if (currentDownTimer<0) currentDownTimer=0;
	
	player.pieceRestante = 100;
	
	if (currentLevel==1) {maxRandom=6;}
	if (currentLevel==4) {maxRandom=7;}
	if (currentLevel==5) {maxRandom=8;}
	if (currentLevel==6) {maxRandom=10;}
	if (currentLevel==10) {maxRandom=13;}
	if (currentLevel==13) {maxRandom=16;}
	if (currentLevel==16) {maxRandom=18;}
	if (currentLevel==19) {maxRandom=20;}
	if (currentLevel==22) {maxRandom=21;}
	
	offset = levels[currentLevel-1];
	while (1)
	{    
		nb = *offset;offset++;
		val= *offset;offset++;
		
		if ((nb==99) && (val==99)) break;
		
		for (k=0;k<nb;k++)
		{
			if (j<220)   // Protection contre débordement en mémoire ?
				gameZone[j] = val;
			j++;	
		}
	}
}

char peekGameZone(char x,char y)
{
	if (x<0) return 99;
	if (x>MAXXGAMEZONE-1) return 99;
	if (y<0) return 99;
	if (y>MAXYGAMEZONE-1) return 99;
	
	return gameZone[y*10+x];
	//return gameZone[x][y];
}


void pokeGameZone(char x,char y,char v)
{
	if ((x>=0) && (x<MAXXGAMEZONE) && (y>=0) && (y<MAXYGAMEZONE))
	gameZone[y*10+x]=v;
}

void initGameZone()
{
	byte px;
	
	px=0;
	
	for (px=0;px<220;px++)
	gameZone[px]=0;

}


void pokePlayerPiece(char pr,char px,char py,char v)
{
	player.piece[pr][px][py]=v;
}

void pokePlayerNextPiece(char px,char py,char v)
{
	player.nextPiece[px+5*py]=v;
}

char peekPlayerPiece(char pr,char px,char py)
{
	return player.piece[pr][px][py];
}

void pokeLignePleineGameZone(char y,char v)
{
	lignePleineGameZone[y] = v;
}

char peekLignePleineGameZone(char y)
{
	return lignePleineGameZone[y];
}

// A utiliser au début du main et à la fin de la destruction
void initLignePleineGameZone(void)
{
	char y;
	
	for (y=0;y<MAXYGAMEZONE;y++)
	pokeLignePleineGameZone(y,0);
}

// Vérifie les lignes pleines du tableau
// Cette fonction ne réinitialise pas le tableau lignePleinGameZone
// Le tableau devrait être réinitialisé à la fin de la destruction
char checkLignePleineGameZone(void)
{
	char res,x,y,cpt;
	res = NOK;
	cpt=0;
	x=0;
	y=0;
	blastRadius = 0;
	
	for (y=0;y<MAXYGAMEZONE;y++)
	{
		cpt=0;
		for (x=0;x<MAXXGAMEZONE;x++)
		{
			// TODO ajouter MegaBomb !!
			if ( (peekGameZone(x,y)==BRIQUE) || (peekGameZone(x,y)==MEGABOMBCODE1) || (peekGameZone(x,y)==MEGABOMBCODE2)|| (peekGameZone(x,y)==MEGABOMBCODE3)|| (peekGameZone(x,y)==MEGABOMBCODE4) || (peekGameZone(x,y)==BOMB))
			cpt++;
		}
		// Si la ligne courant est pleine
		if (cpt==10) {
			blastRadius++;
			// et qu'elle n'est pas déja dans le tableau
			if (peekLignePleineGameZone(y)==0)
			{
				pokeLignePleineGameZone(y,1);// On la met dans le tableau
				res=OK;                   // des lignes pleines
				
			}
		}
	}
	
	return res;
}

// Renvoie OK si pas de collision au nouvelle coordonnées ou nouvelle rotation
char checkCollide(char playerNextLig,char playerNextCol,char playerNextRot)
{
	int x,y;
	
	for (x=0;x<5;x++)
	for (y=0;y<5;y++)
	{
		// On parcoure la matrice de notre pièce à la recherche d'un morceau de la pièce
		if (peekPlayerPiece(playerNextRot,x,y)!=0)
		{
			// Si à l'endroit de ce morceau à afficher il y à quelque
			if (peekGameZone(playerNextCol+x,playerNextLig+y)!=0) return NOK;
		}
		
	}
	
	return OK;
}

// Laisse la brique du joueur dans la gameZone
void putPlayerInGameZone()
{
	int x,y;
	
	for (x=0;x<5;x++)
	for (y=0;y<5;y++)
	{
		// On parcoure la matrice de notre pièce à la recherche d'un morceau de la pièce
		if (peekPlayerPiece(player.rot,x,y)!=0)
		{
			pokeGameZone(player.col+x,player.lig+y,peekPlayerPiece(player.rot,x,y));
		}			
	}
	
	player.pieceRestante--;
	if (player.pieceRestante == 0) workflow = GAMEOVER;
}

void copyNextPiece2Player()
{
	char x,y,i;
	byte b1,b2,b3,b4,b5,t;
	
	i=0;
	
	t=player.nextRandomBombe;
	
	b1=b2=b3=b4=b5=NOK;
		
	if (t==0) b1=OK;
	else
	if (t==1) b1=OK;
	else
	if (t==2) b2=OK;
	else
	if (t==3) b3=OK;
	else
	if (t==4) b4=OK;
	else
	if (t==5) b4=OK;
	else
	if (t==6) {b1=OK;b2=OK;b3=OK;b4=OK;b5=OK;}
	else
	if (t==7) b2=OK;
	else b3=OK;

	// Plus de bombe en niveau facile
	if ((difficulte==3) && (b1!=OK)) b1=OK;	
	
	for (y=0;y<5;y++)
	for (x=0;x<5;x++)
	{
		pokePlayerNextPiece(x,y,0);
		if (pieceData[player.nextCodePiece][i]!=0)
		{
			pokePlayerNextPiece(x,y,BRIQUE);
			if ( ( b1==OK ) && (pieceData[player.nextCodePiece][i]==1) )
			{
				pokePlayerNextPiece(x,y,BOMB);
			}
			if ( ( b2==OK ) && (pieceData[player.nextCodePiece][i]==2) )
			{
				pokePlayerNextPiece(x,y,BOMB);
			}
			if ( ( b3==OK ) && (pieceData[player.nextCodePiece][i]==3) )
			{
				pokePlayerNextPiece(x,y,BOMB);
			}
			if ( ( b4==OK ) && (pieceData[player.nextCodePiece][i]==4) )
			{
				pokePlayerNextPiece(x,y,BOMB);
			}			
			if (t==6)
			{
				pokePlayerNextPiece(x,y,BOMB);
			}
			
		}
		i++;
	}

}

// Copie une pièce de la rom et ses 4 positions !
// p = 0,4,8,...
void copyPiece2Player()
{
	char i,x,y,r;
	byte b1,b2,b3,b4,b5,t;
	
	
	// 1 bombe maxi par pièce, ou toute la pièce en brique, ou toute la pièce en bombe !
	//t = rnd_byte(0,7);
	
	t=player.randomBombe;
	
	b1=b2=b3=b4=b5=NOK;
		
	if (t==0) b1=OK;
	else
	if (t==1) b1=OK;
	else
	if (t==2) b2=OK;
	else
	if (t==3) b3=OK;
	else
	if (t==4) b4=OK;
	else
	if (t==5) b4=OK;
	else
	if (t==6) {b1=OK;b2=OK;b3=OK;b4=OK;b5=OK;}
	else
	if (t==7) b2=OK;
	else b3=OK;

	// Plus de bombe en niveau facile
	if ((difficulte==3) && (b1!=OK)) b1=OK;	
	
	for (r=0;r<4;r++)
	{
		i=0;
		for (y=0;y<5;y++)
		for (x=0;x<5;x++)
		{
			pokePlayerPiece(r,x,y,1);
			if (pieceData[player.codePiece+r][i]==1) 
			{
				if (b1==OK) pokePlayerPiece(r,x,y,2);
			}
			else
			if (pieceData[player.codePiece+r][i]==2) 
			{
				if (b2==OK) pokePlayerPiece(r,x,y,2);
			}
			else
			if (pieceData[player.codePiece+r][i]==3) 
			{
				if (b3==OK) pokePlayerPiece(r,x,y,2);
			}
			else
			if (pieceData[player.codePiece+r][i]==4) 
			{
				if (b4==OK) pokePlayerPiece(r,x,y,2);
			}
			else
			if (pieceData[player.codePiece+r][i]==5) 
			{
				if (b5==OK) pokePlayerPiece(r,x,y,2);
			}
			else
			pokePlayerPiece(r,x,y,pieceData[player.codePiece+r][i]);
			
			i++;
		}
	}
	
	
}

void renderPlayer()
{	
	int x,y;	
	if (player.pieceRestante!=0)
	for (x=0;x<5;x++)
	for (y=0;y<5;y++)
	{
		if (player.piece[player.rot][x][y]!=0)
		{
			put_char(player.x+x,player.y+y,player.piece[player.rot][x][y]);			
		}
	}
}

void renderNextPiece()
{
	//	int x,y;	
	print_at (25,1,str(player.pieceRestante));
	print_at (25,1,"  ");
	if (difficulte<6)	
		put_frame(&player.nextPiece,26,3,5,5);
		
	if (player.pieceRestante<=1)
		put_frame(&vide,26,3,5,5);
	/*	for (x=0;x<5;x++)
	for (y=0;y<5;y++)
	{
		put_char(25+x,5+y,player.nextPiece[x][y]);			
	}*/
}

void playerRotate(char sens)
{
	char nextRotate;
	nextRotate = player.rot;
	if (sens==HORAIRE) nextRotate++; else nextRotate--;
	//nextRotate=player.rot+sens;
	if (nextRotate>3) nextRotate = 0;
	if (nextRotate<0) nextRotate = 3;
	
	// TODO : Vérifier que la rotation est possible à l'écran !!
	if (checkCollide(player.lig,player.col,nextRotate)==OK)
	{
		//copyPlayer2OldLight();
		if (sens==HORAIRE) player.rot++; else player.rot--;
		if (player.rot>3) player.rot = 0;
		if (player.rot<0)  player.rot = 3;
	}	
}

void eraseGameZone()
{
	char x,y;
	for (x=0;x<MAXXGAMEZONE;x++)
	for (y=0;y<MAXYGAMEZONE;y++)
	pokeGameZone(x,y,0);
}

void transformBomb2MegaBomb(void)
{
	char x,y;
	x=0;
	y=0;
	for (y=0;y<MAXYGAMEZONE;y++)
	for (x=0;x<MAXXGAMEZONE;x++)
	{
		if (
				(peekGameZone(x,y) == BOMB) &&
				(peekGameZone(x+1,y) == BOMB) &&
				(peekGameZone(x,y+1) == BOMB) &&
				(peekGameZone(x+1,y+1) == BOMB)
				)
		{
			pokeGameZone(x,y,MEGABOMBCODE1);
			pokeGameZone(x+1,y,MEGABOMBCODE2);
			pokeGameZone(x,y+1,MEGABOMBCODE3);
			pokeGameZone(x+1,y+1,MEGABOMBCODE4);
		}
		
		if ((peekGameZone(x,y) == MEGABOMBCODE1) && (peekGameZone(x+1,y) != MEGABOMBCODE2)) pokeGameZone(x,y,BOMB);
		if ((peekGameZone(x,y) == MEGABOMBCODE2) && (peekGameZone(x-1,y) != MEGABOMBCODE1)) pokeGameZone(x,y,BOMB);
		if ((peekGameZone(x,y) == MEGABOMBCODE3) && (peekGameZone(x+1,y) != MEGABOMBCODE4)) pokeGameZone(x,y,BOMB);
		if ((peekGameZone(x,y) == MEGABOMBCODE4) && (peekGameZone(x-1,y) != MEGABOMBCODE3)) pokeGameZone(x,y,BOMB);
		
	}	
}

void renderGameZone()
{
	put_frame(&gameZone,GAMEZONESTARTX,0,MAXXGAMEZONE,MAXYGAMEZONE);	
	print_at(2,1, "SCORE");
	print_at(2,2, str(player.score));
	
	print_at(2,4, "LEVEL");
	print_at(1,5, str(currentLevel));
	print_at(1,5, "   ");
	
}

void movePlayerRight(void)
{
	if (checkCollide(player.lig,player.col+1,player.rot)==OK)
	{
		player.col++;
		player.x++;
	}
}

void movePlayerLeft(void)
{
	if (checkCollide(player.lig,player.col-1,player.rot)==OK)
	{
		player.col--;
		player.x--;
	}
}

char movePlayerDown(void)
{
	char res;
	
	if (checkCollide(player.lig+1,player.col,player.rot)==OK)
	{
		player.lig++;
		player.y++;
		res = OK;
	}	
	else res = NOK;
	
	return res;
}

// OK = GameOver
char checkGameOver(void)
{
	char res;
	
	if (checkCollide(player.lig+1,player.col,player.rot)==OK)
	{
		res = NOK;
	}	
	else res = OK;
	
	return res;
}

void initPlayer(char reinit)
{		
	player.x = GAMEZONESTARTX + PLAYERSTARTX;     	
	player.oldx = GAMEZONESTARTX + PLAYERSTARTX;
	
	player.y = 0;
	player.oldy = 0;
	
	player.col = PLAYERSTARTX;
	player.oldCol = PLAYERSTARTX;
	
	player.lig = 0;
	player.oldLig = 0;
	
	player.rot=0;
	player.oldRot=0;
	
	if (reinit==INIT) {
		player.codePiece = (rnd_byte(0,maxRandom))*4; // INIT
		player.randomBombe = rnd_byte(0,7);
		player.nextCodePiece = (rnd_byte(0,maxRandom))*4; // INIT
		player.nextRandomBombe = rnd_byte(0,7);
	}
	else
	{
		player.codePiece = player.nextCodePiece; // REINIT
		player.randomBombe = player.nextRandomBombe;
		player.nextCodePiece = (rnd_byte(0,maxRandom))*4; // REINIT
		while (player.nextCodePiece==player.codePiece)
		{
			player.nextCodePiece = (rnd_byte(0,maxRandom))*4;
		}
		player.nextRandomBombe = rnd(0,7);
		if (cheat>0)
		{
			cheat--;
			player.nextRandomBombe =6;
		}		
	}
	
	copyPiece2Player();
	copyNextPiece2Player();	
	
	if (reinit==INIT) doRenderNextPiece=OK; //REINIT

}

// Detruit les zones vides et bombes marquées.
void blastGameZone(char x,char y,char power)
{
	char px,py;
	char c,p;
	char bornexmin,bornexmax,borneymin,borneymax;
	
	c=0;
	px=0;
	py=0;
	
	bornexmin = x-3;
	bornexmax = x+3+1;
	borneymin = y-power+1;
	borneymax = y+power-1+1;
	
	pokeGameZone(x,y,VIDE);
	
	for (px = bornexmin;px<bornexmax;px++)
	for (py = borneymin;py<borneymax;py++)
	{
		if ( (px>=0) && (px<MAXX) && (py>=0) && (py<MAXY) )
		{
			p = peekGameZone(px,py);
			
			if ((p==VIDE) || /*|| (p==BOMBMARQUE) || (p==MEGABOMBMARQUE) ||*/ (p==BRIQUE))
			{
				pokeGameZone(px,py,DETRUIT);
			}		
			
			// On va marquer les autres bombes déclenchées par l'explosion
			if ( p==BOMB )
			{
				pokeGameZone(px,py,BOMBMARQUEPASS2);

			}	
			if ( (p==MEGABOMBCODE1) || (p==MEGABOMBCODE2) || (p==MEGABOMBCODE3) || (p==MEGABOMBCODE4) )
			{
				pokeGameZone(px,py,MEGABOMBMARQUEPASS2);
			}	

		}			
	}	
}

void megaBlastGameZone(char x,char y)
{
	char px,py;
	char c,p;
	char bornexmin,bornexmax,borneymin,borneymax,power;
	
	c=0;
	px=0;
	py=0;
	power=6;
	
	bornexmin = x-5;
	bornexmax = x+5+1;
	borneymin = y-power+1;
	borneymax = y+power-1+1;
	
	pokeGameZone(x,y,VIDE);
	pokeGameZone(x+1,y,VIDE);
	pokeGameZone(x,y+1,VIDE);
	pokeGameZone(x+1,y+1,VIDE);
	
	for (px = bornexmin;px<bornexmax;px++)
	for (py = borneymin;py<borneymax;py++)
	{
		if ( (px>=0) && (px<MAXX) && (py>=0) && (py<MAXY) )
		{
			p = peekGameZone(px,py);
			if ((p==VIDE) || /*(p==BOMBMARQUE) || (p==MEGABOMBMARQUE) || */(p==BRIQUE))
			{
				pokeGameZone(px,py,DETRUIT);
			}		
			
			// On va marquer les autres bombes déclenchées par l'explosion
			if ( p==BOMB )
			{
				pokeGameZone(px,py,BOMBMARQUEPASS2);
			}	
			if ( (p==MEGABOMBCODE1) || (p==MEGABOMBCODE2) || (p==MEGABOMBCODE3) || (p==MEGABOMBCODE4) )
			{
				pokeGameZone(px,py,MEGABOMBMARQUEPASS2);
			}	

		}			
	}	
}

void renderBlast(char x,char y,char power,char b)
{

	char px,py;
	char c;
	char bornexmin,bornexmax,borneymin,borneymax;
	
	c=0;
	px=0;
	py=0;
	
	bornexmin = x-b;
	bornexmax = x+b+1;
	borneymin = y-power+1;
	borneymax = y+power-1+1;
	
	
	for (px = bornexmin;px<bornexmax;px++)
	for (py = borneymin;py<borneymax;py++)
	{
		if ( (px>=0) && (px<MAXX) && (py>=0) && (py<MAXY) )
		{
			c=100;
			if (power==1)
			{
				c=100;
				//if (px==bornexmin) c=104;
				//if (px==(bornexmax-1)) c=112;    
				if (px==x) c=2;  
			}
			else
			{
				if ((px==bornexmin) && (py==borneymin)) c=91; // Coin haut gauche
				else if ( (px==(bornexmax-1)) && (py==borneymin) ) c=107; // Coin haut droit
				else if ( (px==bornexmin) && (py==(borneymax-1)) ) c=93 ; // coin bas gauche
				else if ( (px==(bornexmax-1)) && (py==(borneymax-1)) ) c=109 ; // coin bas droit
				else if ( (px==x) && (py==y) ) c=2;
				/*  else if ( px==bornexmin ) c=150;
					else if ( px==bornexmax-1 ) c=166;
					else if ( py==borneymin ) c=157;
					else if ( py==borneymax-1 ) c=159;*/
				
			}
			
			put_char(px,py,c);
			
		}
	}
}

void newRenderMegaBlast(char x,char y,char b)
{

	char px,py;
	char c;
	char bornexmin,bornexmax,borneymin,borneymax,power;
	
	c=0;
	px=0;
	py=0;
	power=6;
	
	bornexmin = x-b;
	borneymin = y-power+1;
	
	bornexmax = x+1;	
	borneymax = y+power-1+1;
	
	disable_nmi();
	for (px = bornexmin;px<bornexmax;px++)
	{
		for (py = borneymin;py<borneymax;py++)
		{
			if ( (px>=0) && (px<MAXX) && (py>=0) && (py<MAXY) )
			{
				c=100;
				if ((px==bornexmin) && (py==borneymin)) c=91; // Coin haut gauche
				else if ( (px==(bornexmax-1)) && (py==borneymin) ) c=107; // Coin haut droit
				else if ( (px==bornexmin) && (py==(borneymax-1)) ) c=93 ; // coin bas gauche
				else if ( (px==(bornexmax-1)) && (py==(borneymax-1)) ) c=109 ; // coin bas droit
				else if ( (px==x) && (py==y) ) c=2;
				/*  else if ( px==bornexmin ) c=150;
						else if ( px==bornexmax-1 ) c=166;
						else if ( py==borneymin ) c=157;
						else if ( py==borneymax-1 ) c=159;*/
			
			
				put_char(px,py,c);
			
			}
		}
	}
	enable_nmi();
	delay(1);
	
	bornexmin = x;
	bornexmax = x+b+1;
	borneymin = y-power+1;
	borneymax = y+power-1+1;
	
	disable_nmi();
	for (px = bornexmin;px<bornexmax;px++)
	{	
		for (py = borneymin;py<borneymax;py++)
		{
			if ( (px>=0) && (px<MAXX) && (py>=0) && (py<MAXY) )
			{
				c=100;
				if ((px==bornexmin) && (py==borneymin)) c=91; // Coin haut gauche
				else if ( (px==(bornexmax-1)) && (py==borneymin) ) c=107; // Coin haut droit
				else if ( (px==bornexmin) && (py==(borneymax-1)) ) c=93 ; // coin bas gauche
				else if ( (px==(bornexmax-1)) && (py==(borneymax-1)) ) c=109 ; // coin bas droit
				else if ( (px==x) && (py==y) ) c=2;
			/*  else if ( px==bornexmin ) c=150;
					else if ( px==bornexmax-1 ) c=166;
					else if ( py==borneymin ) c=157;
					else if ( py==borneymax-1 ) c=159;*/
			
			
				put_char(px,py,c);
			
			}
		}
	}
	enable_nmi();
	delay(1);
	
}

char marqueBombes()
{
	char i,j,res;
	res=NOK;
	for (i=0;i<MAXYGAMEZONE;i++)
	if (peekLignePleineGameZone(i)==1)
	{
		for (j=0;j<10;j++)
		{
			if (peekGameZone(j,i)==BOMB)
			{
				pokeGameZone(j,i,BOMBMARQUE); // Flag la bombe normale prête à péter !
				res=OK;
			}
			if ( (peekGameZone(j,i)==MEGABOMBCODE1) || (peekGameZone(j,i)==MEGABOMBCODE2) || (peekGameZone(j,i)==MEGABOMBCODE3) || (peekGameZone(j,i)==MEGABOMBCODE4) )
			{     
				pokeGameZone(j,i,MEGABOMBMARQUE); // Flag la bombe normale prête à péter !
				res=OK;
			}
		}
	}   
	return res;
}

// OK --> Il en reste à réduire
// NOK --> Tout est réduit
char reduceGameZone()
{
	char rx,ry,current,next,res;
	
	res = NOK;
/*	
	for (rx=0;rx<MAXXGAMEZONE;rx++)
	for (ry=MAXYGAMEZONE-1;ry>=0;ry--)
	{
		current = peekGameZone(rx,ry);
		next = peekGameZone(rx,ry+1);
		
		if  ( (current>VIDE) && (current!=DETRUIT) && (next==DETRUIT) )
		{
			pokeGameZone(rx,ry+1,peekGameZone(rx,ry));
			pokeGameZone(rx,ry,DETRUIT);
			res = OK;
		}
		
	}
*/	
	if (res==NOK)
	{
		for (rx=0;rx<MAXXGAMEZONE;rx++)
		for (ry=0;ry<MAXYGAMEZONE;ry++)
		{
			current = peekGameZone(rx,ry);
			if (current==DETRUIT) pokeGameZone(rx,ry,VIDE);
		}
	}
	
	return res;
}

// OK --> Il en reste à réduire
// NOK --> Tout est réduit
char reduceGameZone2()
{
	char reduire,debutx,finx,rx,ry,px,marque;
	
	reduire = NOK;
	marque=1;
	debutx=finx=-1;
	px=0;
	
	for (ry=MAXYGAMEZONE;ry>=0;ry--)
	{
		debutx=finx=-1;
		
		for (rx=0;rx<MAXXGAMEZONE;rx++)
		{
			marque=1;
			// put_char(rx,ry,peekGameZone(rx,ry));showBuffer();
			if ( (peekGameZone(rx,ry)>VIDE) && (debutx==-1) )
			{
				debutx = rx;
			}
			if ((rx==9) && (peekGameZone(rx,ry)>VIDE))
			{
				finx=9;
			}
			if ( (peekGameZone(rx,ry)==VIDE) && (debutx!=-1) )
			{
				finx = rx-1;
			}
			
			//if ((peekGameZone(rx,ry+1)!=VIDE) && (debutx!=-1)) marque = 0;
			
			if (finx!=-1)
			{
				for (px=debutx;px<finx+1;px++)
				{
					if ((peekGameZone(px,ry+1)!=VIDE) && (debutx!=-1)) marque = 0;
				}
				if (marque==1)
				{
					reduire = OK;
					for (px=debutx;px<finx+1;px++)
					{
						pokeGameZone(px,ry+1,peekGameZone(px,ry));
						pokeGameZone(px,ry,VIDE);
					}
				}
				debutx=-1;
				finx=-1;
			}
		}
		
	}
	return reduire;
}

void showFond()
{
	char c = currentLevel;
	
	if ((c==1) || (c==6) ||(c==11) || (c==16) || (c==21)) rle2vram(NAMERLE1,buffer);
	else
	if ((c==2) || (c==7) ||(c==12) || (c==17) || (c==22)) rle2vram(NAMERLE2,buffer);
	else
	if ((c==3) || (c==8) ||(c==13) || (c==18) || (c==23)) rle2vram(NAMERLE3,buffer);
	else
	if ((c==4) || (c==9) ||(c==14) || (c==19) || (c==24)) rle2vram(NAMERLE4_1,buffer);
	else
	if ((c==5) || (c==10) ||(c==15) || (c==20) || (c==25)) rle2vram(NAMERLE4_2,buffer);
	
}

char isGameZoneEmpty()
{
	char res,rx,ry;
	res = OK;
	
	for (rx=0;rx<MAXXGAMEZONE;rx++)
	for (ry=0;ry<MAXYGAMEZONE;ry++)
	if (peekGameZone(rx,ry)!=VIDE) return NOK;
	
	return res;
	
}

void setYellowColor(void)
{
		put_vram_pattern (coltab+65*8,yellow_font,8,26);
		put_vram_pattern (coltab+48*8,yellow_font,8,10);
		put_vram_pattern (coltab+32*8,yellow_font,8,1);
		
		put_vram_pattern (coltab+2048+65*8,yellow_font,8,26);
		put_vram_pattern (coltab+2048+48*8,yellow_font,8,10);
		put_vram_pattern (coltab+2048+32*8,yellow_font,8,1);
		
		put_vram_pattern (coltab+4096+65*8,yellow_font,8,26);
		put_vram_pattern (coltab+4096+48*8,yellow_font,8,10);
		put_vram_pattern (coltab+4096+32*8,yellow_font,8,1);
}

void setBleuClairColor(void)
{
		put_vram_pattern (coltab+65*8,bleuclair_font,8,26);
		put_vram_pattern (coltab+48*8,bleuclair_font,8,10);
		put_vram_pattern (coltab+32*8,bleuclair_font,8,1);
		
		put_vram_pattern (coltab+2048+65*8,bleuclair_font,8,26);
		put_vram_pattern (coltab+2048+48*8,bleuclair_font,8,10);
		put_vram_pattern (coltab+2048+32*8,bleuclair_font,8,1);
		
		put_vram_pattern (coltab+4096+65*8,bleuclair_font,8,26);
		put_vram_pattern (coltab+4096+48*8,bleuclair_font,8,10);
		put_vram_pattern (coltab+4096+32*8,bleuclair_font,8,1);
}

void setBleuFonceColor(void)
{
		put_vram_pattern (coltab+65*8,bleufonce_font,8,26);
		put_vram_pattern (coltab+48*8,bleufonce_font,8,10);
		put_vram_pattern (coltab+32*8,bleufonce_font,8,1);
		
		
		put_vram_pattern (coltab+2048+65*8,bleufonce_font,8,26);
		put_vram_pattern (coltab+2048+48*8,bleufonce_font,8,10);
		put_vram_pattern (coltab+2048+32*8,bleufonce_font,8,1);
		
		put_vram_pattern (coltab+4096+65*8,bleufonce_font,8,26);
		put_vram_pattern (coltab+4096+48*8,bleufonce_font,8,10);
		put_vram_pattern (coltab+4096+32*8,bleufonce_font,8,1);
}

void setBleuMoyenColor()
{
		put_vram_pattern (coltab+65*8,bleumoyen_font,8,26);
		put_vram_pattern (coltab+48*8,bleumoyen_font,8,10);
		put_vram_pattern (coltab+32*8,bleumoyen_font,8,1);
		
		put_vram_pattern (coltab+2048+65*8,bleumoyen_font,8,26);
		put_vram_pattern (coltab+2048+48*8,bleumoyen_font,8,10);
		put_vram_pattern (coltab+2048+32*8,bleumoyen_font,8,1);
		
		put_vram_pattern (coltab+4096+65*8,bleumoyen_font,8,26);
		put_vram_pattern (coltab+4096+48*8,bleumoyen_font,8,10);
		put_vram_pattern (coltab+4096+32*8,bleumoyen_font,8,1);
}

void loadPatternAndColor(void)
{
	char c = currentLevel;
	
	if ((c==1) || (c==6) ||(c==11) || (c==16) ||(c==21))
	{
		load_patternrle(PATTERNRLE1);
		duplicate_pattern();
		
		/* Chargement des couleurs */
		rle2vram(COLORRLE1,coltab);
		rle2vram(COLORRLE1,coltab+2048);
		rle2vram(COLORRLE1,coltab+4096);
		
		setYellowColor();
	}
	if ((c==2) || (c==7) ||(c==12) || (c==17) ||(c==22))
	{
		load_patternrle(PATTERNRLE2);
		duplicate_pattern();
		
		/* Chargement des couleurs */
		rle2vram(COLORRLE2,coltab);
		rle2vram(COLORRLE2,coltab+2048);
		rle2vram(COLORRLE2,coltab+4096);
		
		setBleuClairColor();
	}
	if ((c==3) || (c==8) ||(c==13) || (c==18) ||(c==23))
	{
		load_patternrle(PATTERNRLE3);
		duplicate_pattern();
		
		/* Chargement des couleurs */
		rle2vram(COLORRLE3,coltab);
		rle2vram(COLORRLE3,coltab+2048);
		rle2vram(COLORRLE3,coltab+4096);
		
		setBleuFonceColor();
	}
	if ((c==4) || (c==9) ||(c==14) || (c==19) ||(c==24))
	{
		load_patternrle(PATTERNRLE4);
		duplicate_pattern();
		
		/* Chargement des couleurs */
		rle2vram(COLORRLE4,coltab);
		rle2vram(COLORRLE4,coltab+2048);
		rle2vram(COLORRLE4,coltab+4096);
		
		setBleuFonceColor();
	}
	if ((c==5) || (c==10) ||(c==15) || (c==20) ||(c==25))
	{
		load_patternrle(PATTERNRLE4);
		duplicate_pattern();
		
		/* Chargement des couleurs */
		rle2vram(COLORRLE4,coltab);
		rle2vram(COLORRLE4,coltab+2048);
		rle2vram(COLORRLE4,coltab+4096);
		
		setBleuMoyenColor();
	}
}
void calculeCheat(void)
{
	char rx,ry,current;
	unsigned res;
	
	res = 0;

	if (difficulte<5) // Si le mode de difficulté est easy ou normal
	{
		for (rx=0;rx<MAXXGAMEZONE;rx++)
		for (ry=0;ry<MAXYGAMEZONE;ry++)
		{
			current = peekGameZone(rx,ry);
			if (current!=0) res++;
		}
	
		if (res<6) cheat = 3; // Si il reste moins de 6 briques, on cheat
		
	} else cheat = 0;

}

void main(void)
{
	char toucheRelachee,i,j,k;

	endGame = NOK;
	cheat = 0;
	difficulte = 4;
	typectrl = TYPE1;
	
	maxRandom = 6;
	workflow = MENU;
	currentLevel=1;

	blastRadius = 0;
	delaiToucheGauche=0;
	delaiToucheDroite=0;
	delaiToucheFire1=0;
	
	doRenderPlayer=NOK;
	doRenderNextPiece = NOK;
	doRenderGameZone=NOK;
	
	doRenderExplosion=NOK;

	currentDownTimer = DOWNTIMER;
	downTimer= currentDownTimer;
	
	set_snd_table(snd_table);
	screen_mode_2_bitmap();
	stop_music();
	stop_sound(2);
	stop_sound(3);
	stop_sound(4);
	stop_sound(5);
	
	screen_off();
	rle2vram(NAMERLE_TITLE,chrtab);	
	load_patternrle(PATTERNRLE_TITLE);
	duplicate_pattern();
		
	/* Chargement des couleurs */
	rle2vram(COLORRLE_TITLE,coltab);
	rle2vram(COLORRLE_TITLE,coltab+2048);
	rle2vram(COLORRLE_TITLE,coltab+4096);	
	
	for (i=5;i<26;i++)
	for (j=12;j<19;j++)
		put_char(i,j,0);
		
	screen_on();
	pause();
	
	screen(name_table1,name_table2);
	
	disable_nmi();	

	rle2vram(NAMERLE_TITLE,buffer);	
	for (i=17;i<24;i++)
	for (j=11;j<14;j++)
		put_char(i,j,0);
		
	for (i=7;i<25;i++)
	for (j=14;j<19;j++)
		put_char(i,j,0);


		showBuffer();
	enable_nmi();
	playExplosion();
	delay(60);
	
	disable_nmi();	

	rle2vram(NAMERLE_TITLE,buffer);	
		
	for (i=7;i<25;i++)
	for (j=14;j<19;j++)
		put_char(i,j,0);


		showBuffer();
	enable_nmi();
	playExplosion();
	delay(60);

	disable_nmi();	

	rle2vram(NAMERLE_TITLE,buffer);	
	showBuffer();
	enable_nmi();
	playExplosion();
	pause();
	
	

	disable_nmi();
	screen_off();
	fill_vram(0,0,0x4000);

	loadPatternAndColor();
	
	screen_on();
	enable_nmi();
	//play_music(smurfmusic1);
	initLignePleineGameZone();
	
	initGameZone();
	

	while (1)
	{     		
		/*--------------------------------------------------------------------------------*/
		/*---------------------------- MENU ----------------------------------------------*/
		/*--------------------------------------------------------------------------------*/
		if (workflow==MENU)
			{	
			stop_music();
			currentLevel=1;
			screen_off();
			loadPatternAndColor();
			initLignePleineGameZone();
			player.score=0;
			delay(1);
			cls();
			showBuffer();
			screen_on();
			
			delaiToucheDroite = 30;
			delaiToucheGauche = 30;
			
			
			k=1;

			while (1)
			{
				if (joypad_1==0) {delaiToucheDroite=0;delaiToucheGauche=0;delaiToucheFire1=0;}
				if ( (joypad_1 & UP) && (delaiToucheDroite==0)) {k--;delaiToucheDroite=30;stop_sound(2);play_sound(2);}
				if ( (joypad_1 & DOWN)  && (delaiToucheGauche==0)) {k++;delaiToucheGauche=30;stop_sound(2);play_sound(2);}
				if  ( ((joypad_1 & FIRE2) || (joypad_1 & FIRE1))  && (k==1) ) {stop_sound(3);play_sound(3);break;}
				if  ( ((joypad_1 & FIRE2) || (joypad_1 & FIRE1))  && (k==2) && (delaiToucheFire1==0))  
				{
					stop_sound(2);play_sound(2);
					if (typectrl==TYPE1) typectrl=TYPE2;
					else if (typectrl==TYPE2) typectrl=TYPE1;					
					delaiToucheFire1=30;
				}
				
				if  ( ((joypad_1 & FIRE2) || (joypad_1 & FIRE1))  && (k==3) && (delaiToucheFire1==0)) 
				{
					stop_sound(2);play_sound(2);
					difficulte++;
					if (difficulte==7) difficulte = 3;
					delaiToucheFire1=30;
				}


				if (k==0) k=1;
				if (k>3) k=3;
			
				delay(1);
				cls();
				
				if (k==1) put_char(3,6,3);
				if (k==2) put_char(3,8,3);
				if (k==3) put_char(3,10,3);
				
				if (difficulte==3) print_at(18,10,"EASIER ");
				if (difficulte==4) print_at(18,10,"NORMAL ");
				if (difficulte==5) print_at(18,10,"HARDER");
				if (difficulte==6) print_at(18,10,"HARDEST");
				
				if (typectrl==TYPE1) print_at(22,8,"TYPE 1");
				if (typectrl==TYPE2) print_at(22,8,"TYPE 2");
				
			
				print_at(5,6,"START");
				print_at(5,8,"CONTROL CONFIG :");
				print_at(5,10,"DIFFICULTY :");
				delay(1);
				showBuffer();
			}
			
			eraseGameZone();

			copyLevel2GameZone();

			
			initPlayer(INIT);

			
			disable_nmi();
			loadPatternAndColor();
			showFond();
			enable_nmi();


			
			delay(1);
			doRenderPlayer=OK;
			doRenderGameZone=OK;
			doRenderNextPiece=OK;
			toucheRelachee=OK;
			downTimer = currentDownTimer;
			endGame = NOK;
			play_music(music);
			workflow=INGAME;
		}
		/* -------------------------------------------------------------------------------*/
		/* ----------------------------- GAMEOVER ----------------------------------------*/
		/* -------------------------------------------------------------------------------*/
		if (workflow==GAMEOVER)
		{
			stop_music();
			doRenderGameZone=OK;
			doRenderPlayer=OK;
			doRenderNextPiece=OK;
			delay(30);
			
			for (i=MAXYGAMEZONE-1;i>=0;i--)
			{   disable_nmi();
				for (j=0;j<MAXXGAMEZONE;j++)
				{
					put_char(j+GAMEZONESTARTX,i+GAMEZONESTARTY,BRIQUE);
				}
				showBuffer();
				enable_nmi();
				stop_sound(3);play_sound(3);
				delay(1);
			}
			for (i=0;i<MAXYGAMEZONE;i++)
			{
				disable_nmi();
				for (j=0;j<MAXXGAMEZONE;j++)
				{
					put_char(j+GAMEZONESTARTX,i+GAMEZONESTARTY,32);
				}
				showBuffer();
				enable_nmi();
				stop_sound(3);play_sound(3);
				delay(1);
			}
			
			
			//cls();
			if (endGame==NOK)
			{
				center_string(6,"GAME OVER");
			}
			else
			{
				center_string(6,"YOU WIN");
			}
			center_string(8,"FINAL");
			center_string(9,"SCORE");
			
			if (difficulte==3)	{center_string(11,"EASY");}
			if (difficulte==4)	{center_string(11,"NORMAL");}
			if (difficulte==5)	{center_string(11,"HARD");}
			if (difficulte==6)	{center_string(11,"HARDEST");}
			
			center_string(12,"MODE");
			
			center_string(14,str(player.score));
			
			showBuffer();
			enable_nmi();
			pause();
			screen_off();
			initLignePleineGameZone();
			workflow=MENU;
		}
		/*--------------------------------------------------------------------------------*/
		/*---------------------------- NEXTLEVEL -----------------------------------------*/
		/*--------------------------------------------------------------------------------*/            
		if (workflow==NEXTLEVEL)
		{
			stop_music();
			disable_nmi();
			screen_off();
			cls();
			setYellowColor();
			showBuffer();
			screen_on();
			enable_nmi();
			
			k=1;
			
			j = player.pieceRestante;
			for (i=0;i<j;i++)
			{
				player.score++;
				player.pieceRestante--;
				
				if  ( ((joypad_1 & FIRE2) || (joypad_1 & FIRE1))) k=0;
				
				if (k!=0)
				{
					disable_nmi();
					print_at(19,10,str(player.pieceRestante));
					print_at(7,10,"LEVEL SCORE  ");

					print_at(19,12,str(player.score));
					print_at(7,12,"TOTAL SCORE");
			
					showBuffer();
					enable_nmi();
					stop_sound(2);play_sound(2);
					delay(1);
				}
			}
			print_at(19,12,str(player.score));
			print_at(7,12,"TOTAL SCORE");
			center_string(10,"READY TO NEXT LEVEL");
			showBuffer();			
			pause();
			
			eraseGameZone();
			currentLevel++;
			if (currentLevel<26)
			{
				copyLevel2GameZone();
			
				initPlayer(INIT);
			
				disable_nmi();
				screen_off();
				loadPatternAndColor();
				showFond();
				showBuffer();
				enable_nmi();
				delay(1);
				doRenderPlayer=OK;
				doRenderNextPiece=OK;
				doRenderGameZone=OK;
				screen_on();
				toucheRelachee=OK;
				cheat = 0;
				workflow=INGAME;
				play_music(music);
			}
			else
			{
				endGame = OK;
				workflow=GAMEOVER;
			}
		}
		/*--------------------------------------------------------------------------------*/
		/*---------------------------- INGAME --------------------------------------------*/
		/*--------------------------------------------------------------------------------*/
		if (workflow==INGAME)
		{
			
			if (joypad_1==0) {toucheRelachee=OK;delaiToucheDroite=0;delaiToucheGauche=0;delaiToucheFire1=0;}
			
			if (typectrl==TYPE1)
			{
				if  ((joypad_1 & FIRE1) && (delaiToucheFire1==0))  {playerRotate(HORAIRE);doRenderPlayer=OK;toucheRelachee=NOK;delaiToucheFire1=TOUCHEDELAI*2;stop_sound(2);play_sound(2);}     		  
				if  ((joypad_1 & FIRE2) && (delaiToucheFire1==0))  {playerRotate(ANTIHORAIRE);doRenderPlayer=OK;toucheRelachee=NOK;delaiToucheFire1=TOUCHEDELAI*2;stop_sound(2);play_sound(2);}     		  
			}
			else
			{
				if  ((joypad_1 & FIRE2) && (delaiToucheFire1==0))  {playerRotate(HORAIRE);doRenderPlayer=OK;toucheRelachee=NOK;delaiToucheFire1=TOUCHEDELAI*2;stop_sound(2);play_sound(2);}     		  
				if  ((joypad_1 & FIRE1) && (delaiToucheFire1==0))  {playerRotate(ANTIHORAIRE);doRenderPlayer=OK;toucheRelachee=NOK;delaiToucheFire1=TOUCHEDELAI*2;stop_sound(2);play_sound(2);}     		  			
			}
			if ( (joypad_1 & RIGHT) && (delaiToucheDroite==0)) {movePlayerRight();doRenderPlayer=OK;delaiToucheDroite=TOUCHEDELAI;}
			if ( (joypad_1 & LEFT)  && (delaiToucheGauche==0)) {movePlayerLeft();doRenderPlayer=OK;delaiToucheGauche=TOUCHEDELAI;}
			
			if (keypad_1==10)
			{
				stop_music();
				stop_sound(3);
				play_sound(3);
				while (keypad_1==10) {}
				delay(1);
				while(keypad_1!=10) {}
				stop_sound(3);
				play_sound(3);
				delay(2);
				play_music(music);
			}
			// DEBUG MODE !!!
			/*
			if (keypad_1==3) workflow = NEXTLEVEL;
			if (keypad_1==4) player.pieceRestante=3;
			if (keypad_1==5) workflow=GAMEOVER;
			if (keypad_1==6) {currentLevel+=5;workflow=NEXTLEVEL;}*/
			
			
			if (( (joypad_1 & DOWN)   || (downTimer==0) ) )
			{  
				if (movePlayerDown()==NOK) // On peut plus descendre on met dans la gameZone
				{
					stop_sound(3);
					play_sound(3);
					putPlayerInGameZone();
					transformBomb2MegaBomb();
					// AJOUT 1.1
					disable_nmi();
					renderGameZone(); 
					showBuffer();
					enable_nmi();
					// FIN AJOUT 1.1
					if (checkLignePleineGameZone()==OK)
					{
						workflow = RENDERLIGNEPLEINE;
						doRenderGameZone = NOK;     					     
						
					} else
					{	         
						initPlayer(REINIT);					
						if (checkGameOver()==OK) workflow = GAMEOVER;
						doRenderPlayer=OK; 
						doRenderNextPiece=OK;	                  	     				
					}                         	     
				}  else {doRenderPlayer=OK;doRenderNextPiece=OK;}   			     	
				
				toucheRelachee=NOK;		
				
				if (downTimer==0) downTimer = currentDownTimer;
			}	
		}

		/*--------------------------------------------------------------------------------*/
		/*---------------------------- DETECT --------------------------------------------*/
		/*--------------------------------------------------------------------------------*/     	  	
		if (workflow==DETECT) 
		{
			if (marqueBombes()==OK)
			workflow=EXPLODE1;
			else
			{
				workflow=INGAME;
				initPlayer(REINIT);
				if (checkGameOver()==OK) workflow = GAMEOVER;
				
				
			}
		}

		/*--------------------------------------------------------------------------------*/
		/*---------------------------- EXPLODE1 ------------------------------------------*/
		/*--------------------------------------------------------------------------------*/    
		if (workflow==EXPLODE1)
		{
			
			doRenderExplosion=OK;                       
		} 	  	
		
		/* -------------------------------------------------------------------------------*/
		/* ---------------------------- EXPLODE2 -----------------------------------------*/
		/* -------------------------------------------------------------------------------*/
		if (workflow==EXPLODE2)
		{
			for (i=0;i<MAXYGAMEZONE;i++)
			{
				for (j=0;j<MAXXGAMEZONE;j++)
				{	  // TODO : Gérer le cas de la mégabombe !
					if (peekGameZone(j,i)==BOMBMARQUE)
					{
						blastGameZone(j,i,blastRadius);
						playExplosion();
					}
					if (peekGameZone(j,i)==MEGABOMBMARQUE)
					{
						megaBlastGameZone(j,i);
						playExplosion();
					}
				}
			}
			
			workflow = EXPLODE3;
		}
		
		/* -------------------------------------------------------------------------------*/
		/* ----------------------------- EXPLODE 3 ---------------------------------------*/
		/* -------------------------------------------------------------------------------*/
		if (workflow==EXPLODE3)
		{
			k=0;
			initLignePleineGameZone();
			for (i=0;i<MAXYGAMEZONE;i++)
			for (j=0;j<MAXXGAMEZONE;j++)
			{
				if (peekGameZone(j,i)==BOMBMARQUEPASS2)
				{
					pokeLignePleineGameZone(i,1);
					pokeGameZone(j,i,BOMBMARQUE);
					k=1;
				}
				if (peekGameZone(j,i)==MEGABOMBMARQUEPASS2)
				{
					pokeLignePleineGameZone(i,1);
					pokeGameZone(j,i,MEGABOMBMARQUE);
					k=1;
				}
			}
			if (k==0) workflow = REDUCE; else workflow = EXPLODE1;
		}

		/* -------------------------------------------------------------------------------*/
		/* ----------------------------- REDUCE ------------------------------------------*/
		/* -------------------------------------------------------------------------------*/
		if (workflow==REDUCE)
		{
			while (reduceGameZone()==OK)
			{            
				disable_nmi();
				renderGameZone();
				enable_nmi();
				delay(1);
				disable_nmi();
				showBuffer();
				enable_nmi();
				delay(1);
			}    
			while (reduceGameZone2()==OK)
			{            		
				disable_nmi();
				renderGameZone();
				enable_nmi();
				delay(1);
				disable_nmi();
				showBuffer();
				enable_nmi();
				delay(1);
			}       	
			
			calculeCheat();
			
			disable_nmi();
			showFond();
			enable_nmi();
			delay(1);    
			// AJOUT 1.1
			transformBomb2MegaBomb();
			disable_nmi();
			renderGameZone(); 
			enable_nmi();
			// FIN AJOUT 1.1
			delay(1);
			disable_nmi();
			showBuffer();
			enable_nmi();
			delay(1);     	        	            			
			initLignePleineGameZone();
			workflow = INGAME;
			initPlayer(REINIT);
			if (checkGameOver()==OK) workflow = GAMEOVER;
			if (isGameZoneEmpty()==OK) {initLignePleineGameZone();workflow = NEXTLEVEL;}
			
		}
		
		
		/*--------------------------------------------------------------------------------*/
		/*--------------------------- RENDERING D'ANIMATION ------------------------------*/
		/*--------------------------------------------------------------------------------*/
		
		/*--------------------------------------------------------------------------------*/
		/* ------------------------------------- EXPLOSIONS ------------------------------*/
		/* -------------------------------------------------------------------------------*/
		if (doRenderExplosion==OK)
		{
			//disable_nmi();
			doRenderExplosion = NOK;
			screen(name_table1,name_table1);
			for (i=0;i<MAXYGAMEZONE;i++)
			{
				if (lignePleineGameZone[i]==1) // Y'a des bombes à faire péter ?
				{
					for (j=0;j<MAXXGAMEZONE;j++)
					{   // TODO : TRAITER LE CAS DE LA MEGABOMBE !!
						if (peekGameZone(j,i)==BOMBMARQUE)
						{
							//disable_nmi();
							for (k=1;k<4;k++)
							{
								disable_nmi();
								renderBlast(GAMEZONESTARTX+j,GAMEZONESTARTY+i,blastRadius,k);
								enable_nmi();
								delay(1);
							}
							//enable_nmi();
						}
						if (peekGameZone(j,i)==MEGABOMBMARQUE)
						{
							pokeGameZone(j+1,i,VIDE);
							pokeGameZone(j,i+1,VIDE);
							pokeGameZone(j+1,i+1,VIDE);

							for (k=3;k<6;k++)
							{					
								newRenderMegaBlast(GAMEZONESTARTX+j,GAMEZONESTARTY+i,k);								
							}
						}
					}
				}
			}
			screen(name_table1,name_table2);
			//enable_nmi();//pause();
			delay(1); 
			workflow = EXPLODE2;
			
		}
		
		/* -------------------------------------------------------------------------------------*/
		/* ------------------------------ ANIMATION DETECTION DES LIGNES PLEINES ---------------*/
		/* -------------------------------------------------------------------------------------*/
		
		if (workflow==RENDERLIGNEPLEINE)
		{
			//disable_nmi();
			for (i=0;i<MAXYGAMEZONE;i++)
			if (peekLignePleineGameZone(i)==1)
			{
				for (j=0;j<10;j++)
				{
					
					k = peekGameZone(j,i);
					if ( (k==14) || (k==22) || (k==15) || (k==23) || (k==1) ||(k==2) )
					{
						disable_nmi();
						put_char(GAMEZONESTARTX+j,i,peekGameZone(j,i)+96);
						showBuffer();
						enable_nmi();
						delay(1);
					}
				}
			}
			//enable_nmi();
			//delay(1);
			workflow = DETECT;
		}      
		
	if ((doRenderGameZone==OK) || (doRenderPlayer==OK) || (doRenderNextPiece==OK))
	{
		disable_nmi();
		renderGameZone(); 
		enable_nmi();
		if (doRenderNextPiece==OK)
		{
			delay(1);
			renderNextPiece();
			doRenderNextPiece=NOK;
		}
		if (doRenderGameZone==OK)
		{
			doRenderGameZone=NOK;                 
		}
		if (doRenderPlayer==OK)
		{
			delay(1);
			renderPlayer();                       
			doRenderPlayer=NOK;
		}
		//center_string(20,str(maxRandom));
		//center_string(21,str(player.nextCodePiece/4));
		disable_nmi();
		showBuffer();
		enable_nmi();
	}

		delay(1);
	}
	
	pause();

}

void nmi(void) 
{
	if (downTimer>0) downTimer--;
	if (delaiToucheGauche>0) delaiToucheGauche--;
	if (delaiToucheDroite>0) delaiToucheDroite--;
	if (delaiToucheFire1>0) delaiToucheFire1--;

	/* OPERATIONS DE RENDERING */ 

	update_music();
}
