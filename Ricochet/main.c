#include "ricochet.h"

int main(void){
	Choix choix;
	int score;
	int i;
	Carte map;
	Carte mapEdit[7];

	
	// Robots
	Position Bender, WallE, R2D2, Marvin;
	do{
		HOME:
		Home(&choix);
		score=0;
		map.nbJoueur=1;

		switch(choix.Menu){
			case 1:
				GrilleAleatoire(&map, &Bender, &WallE, &R2D2, &Marvin);
				Play(&map, &Bender, &WallE, &R2D2, &Marvin, &score);
				if(score==0){
					do{
						AffichageLose(&map);
						printf("[0] Retour\n");
						scanf("%d", &choix.Grille);
					}while(choix.Grille!=0);
				}else{
					do{
						AffichageWin(&map, score);
						HIsave(score);
						printf("[0] Retour\n");
						scanf("%d", &choix.Grille);
					}while(choix.Grille!=0);
				}
			break;
			case 2:
				Menu2(&choix);
				if(choix.Grille==0){
					goto HOME;
				}else{
					if(choix.Grille>3){
						map=mapEdit[choix.Grille-3];
					}else{
						GrilleDefinie(choix, &map, &Bender, &WallE, &R2D2, &Marvin);
					}
				}
				Play(&map, &Bender, &WallE, &R2D2, &Marvin, &score);
				if(score==0){
					do{
						AffichageLose(&map);
						printf("[0] Retour\n");
						scanf("%d", &choix.Grille);
					}while(choix.Grille!=0);
				}else{
					do{
						AffichageWin(&map, score);
						HIsave(score);
						printf("[0] Retour\n");
						scanf("%d", &choix.Grille);
					}while(choix.Grille!=0);
				}
			break;
			case 3:
				Menu3(&choix, &map);
				PlayMulti(&map, &Bender, &WallE, &R2D2, &Marvin, &score, choix, mapEdit);

			break;
			case 4:
				Menu4(&choix);
				if(choix.Grille!=0){
					i=choix.Grille;
					if(choix.Grille<4){
						mapEdit[i].nbJoueur=1;
					}else{
						mapEdit[i].nbJoueur=2;
					}
					Edit(&mapEdit[i], &Bender, &WallE, &R2D2, &Marvin);
				}
			break;
			case 5:
				do{
					Menu5();
					printf("[1] Effacer tous les scores\n\n");
					printf("\n[0] Retour\n");
					scanf("%d", &choix.Grille);
				}while(choix.Grille!=0&&choix.Grille!=1);
				if(choix.Grille==1){
					HIclear();
				}
			break;
		}
	}while(choix.Menu!=0);

	system("clear");
	return 0;
}