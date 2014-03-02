/////////////
// INCLUDE //
/////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////
// DEFINE //
////////////
#define NORMAL  "\x1B[0m"
#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYAN  "\x1B[36m"

///////////////
// STRUCTURE //
///////////////
typedef struct{
	int Menu;
	int Grille;
} Choix;

typedef struct{
	int x,y;
} Position;

typedef struct{
	char Grille[33][33];
	Position Arrive;
	Position Cible[4];
	int nbJoueur;
} Carte;

typedef struct{
	int End;
} Round;

typedef struct{
	char dir;
	char move;
	int size;
} Wall;

typedef struct{
	int pronostique;
	int ordre;
	int win;
} Player;

//////////////
// FONCTION //
//////////////
/* menu.c */
void Home(Choix* choix);
void Menu2(Choix* choix);
void Menu3(Choix* choix, Carte* carte);
void Menu4(Choix* choix);
void Menu5();
void croissant(int m, int t[]);
/* carte.c */
void GrilleDefinie(Choix choix, Carte* carte, Position* bender, Position* wallE, Position* r2d2, Position* marvin);
/* deplacement.c */
void Deplacement(Carte* carte, char move, Position* robot);
void BotDeplacement(Carte* carte, int move, Position* robot);
/* affichage.c */
void AffichageGrille(Carte* carte, Position bender, Position wallE, Position r2d2, Position marvin);
void AffichageWin(Carte* carte, int score);
int AffichageManette(char* move, int score, int nRobot);
void AffichageLose(Carte* carte);
/* aleatoire.c */
int CibleValide(Carte carte);
int CarteValide(Carte* botMap, Position botRobot[]);
void RobotAleatoire(Carte carte, int* VerticalX, int* HorizonX);
void GrilleAleatoire(Carte* carte, Position* bender, Position* wallE, Position* r2d2, Position* marvin);
/* solo.c */
void Play(Carte* map, Position* Bender, Position* WallE, Position* R2D2, Position* Marvin, int* score);
void HIsave(int score);
void HIclear();
/* editor.c */
void WallMove(Carte* carte, Position* curseur, Wall Mur);
void WallSize(Wall* Mur);
void CibleMove(Carte* carte, char move, Position* curseur);
void Edit(Carte* carte, Position* bender, Position* wallE, Position* r2d2, Position* marvin);
/* multi.c */
void PlayMulti(Carte* carte, Position* Bender, Position* WallE, Position* R2D2, Position* Marvin, int* score, Choix choix, Carte mapEdit[]);