#include "ricochet.h"

void PlayMulti(Carte* carte, Position* Bender, Position* WallE, Position* R2D2, Position* Marvin, int* score, Choix choix, Carte mapEdit[]){

	int color[4]; // Couleur du but
	int colorTemp;
	int i,j,k;
	int test;
	int currentPlayer;
	Position temp[4];
	temp[0].x=Bender->x;
	temp[0].y=Bender->y;
	temp[1].x=WallE->x;
	temp[1].y=WallE->y;
	temp[2].x=R2D2->x;
	temp[2].y=R2D2->y;
	temp[3].x=Marvin->x;
	temp[3].y=Marvin->y;

	Player joueur[carte->nbJoueur];
	// Initialisation des objectifs atteints
	for(i=0;i<carte->nbJoueur;i++){
		joueur[i].win=0;
	}
	int jClasse[carte->nbJoueur];
	color[0]=color[1]=color[2]=color[3]=5;
	srandom(time(NULL));

	int nRobot; // Robot utilise en cours de partie
	char move; // Variable de mouvement
	Round tour[4];
	// Booleen 1 = tour gagne | 0 = pas encore gagne
	tour[0].End=0;
	tour[1].End=0;
	tour[2].End=0;
	tour[3].End=0;

	for(i=0;i<4;i++){
		// Definition de la carte a utiliser
		if(choix.Grille>3){
			j=carte->nbJoueur;
			GrilleDefinie(choix, carte, Bender, WallE, R2D2, Marvin);
			*carte=mapEdit[choix.Grille];
			carte->nbJoueur=j;
			Bender->x=temp[0].x;
			Bender->y=temp[0].y;
			WallE->x=temp[1].x;
			WallE->y=temp[1].y;
			R2D2->x=temp[2].x;
			R2D2->y=temp[2].y;
			Marvin->x=temp[3].x;
			Marvin->y=temp[3].y;
		}else{
			GrilleDefinie(choix, carte, Bender, WallE, R2D2, Marvin);
		}
		// Etablissement de la couleur a jouer
		do{
			colorTemp=(random()%4);
		}while((colorTemp==color[0])||(colorTemp==color[1])||(colorTemp==color[2]));
		color[i]=colorTemp;
		// Affichage
		AffichageGrille(carte, *Bender, *WallE, *R2D2, *Marvin);
		if(color[i]==0){printf("\nCouleur : %sVERT%s\n", GREEN, NORMAL);}
		if(color[i]==1){printf("\nCouleur : %sBLEU%s\n", BLUE, NORMAL);}
		if(color[i]==2){printf("\nCouleur : %sJAUNE%s\n", YELLOW, NORMAL);}
		if(color[i]==3){printf("\nCouleur : %sVIOLET%s\n", MAG, NORMAL);}
		// Saisie des pronostiques
		printf("\nJoueur 1, quel est votre pronostique? ");
		scanf("%d", &joueur[0].pronostique);
		jClasse[0]=joueur[0].pronostique;
		for(j=1;j<carte->nbJoueur;j++){
			do{
				printf("\nJoueur %d, quel est votre pronostique? ", j+1);
				scanf("%d", &joueur[j].pronostique);
				jClasse[j]=joueur[j].pronostique;
				test=0;
				for(k=0;k<j;k++){
					if(jClasse[k]==jClasse[j]){
						test=1;
					}
				}
				if(test==1){
					printf("Pronostique deja pris!\n");
				}
			}while(test==1);
		}
		// Classement des pronostiques par ordre croissant
		croissant(carte->nbJoueur, jClasse);
		// Etabli l'ordre de passage des joueurs en fonction du pronostique
		for(j=0;j<carte->nbJoueur;j++){
			k=0;
			while(joueur[k].pronostique!=jClasse[j]){
				k++;
			}
			joueur[k].ordre=j;
		}
		j=0;
		// Recherche du premier joueur
		currentPlayer=0;
		while(joueur[currentPlayer].ordre!=0){
			currentPlayer++;
		}
		// Deroulement d'un tour
		do{
			nRobot=color[i]; // Utilisation par defaut du robot de la couleur du but
			*score=0; // Initialisation du score
			do{
				do{
					AffichageGrille(carte, *Bender, *WallE, *R2D2, *Marvin);
					if(color[i]==0){printf("\nCouleur : %sVERT%s           Joueur : %d            Pronostique : %d", GREEN, NORMAL, currentPlayer+1, joueur[currentPlayer].pronostique);}
					if(color[i]==1){printf("\nCouleur : %sBLEU%s           Joueur : %d            Pronostique : %d", BLUE, NORMAL, currentPlayer+1, joueur[currentPlayer].pronostique);}
					if(color[i]==2){printf("\nCouleur : %sJAUNE%s           Joueur : %d            Pronostique : %d", YELLOW, NORMAL, currentPlayer+1, joueur[currentPlayer].pronostique);}
					if(color[i]==3){printf("\nCouleur : %sVIOLET%s           Joueur : %d            Pronostique : %d", MAG, NORMAL, currentPlayer+1, joueur[currentPlayer].pronostique);}
					AffichageManette(&move, *score, nRobot);
				}while((move!='z')&&(move!='q')&&(move!='s')&&(move!='d')&&(move!='p')&&(move!='m'));
				if(move=='p'){goto OUT;} // Quitter
				// Changement de robot en cours de jeu
				if(move=='m'){
					if(nRobot==3){nRobot=0;}
					else{nRobot++;}
				}
				// Deplacement en fonction du robot choisi
				if(nRobot==0){Deplacement(carte, move, Bender);}
				if(nRobot==1){Deplacement(carte, move, WallE);}
				if(nRobot==2){Deplacement(carte, move, R2D2);}
				if(nRobot==3){Deplacement(carte, move, Marvin);}
				// Augmentation du score
				(*score)++;
				if(color[i]==0){
					if((Bender->y==carte->Cible[0].y)&&(Bender->x==carte->Cible[0].x)){
						tour[0].End=1;
					}
				}
				if(color[i]==1){
					if((WallE->y==carte->Cible[1].y)&&(WallE->x==carte->Cible[1].x)){
						tour[1].End=1;
					}
				}
				if(color[i]==2){
					if((R2D2->y==carte->Cible[2].y)&&(R2D2->x==carte->Cible[2].x)){
						tour[2].End=1;
					}
				}
				if(color[i]==3){
					if((Marvin->y==carte->Cible[3].y)&&(Marvin->x==carte->Cible[3].x)){
						tour[3].End=1;
					}
				}
			}while((*score<=joueur[currentPlayer].pronostique-1)&&(tour[color[i]].End!=1));
			if(tour[color[i]].End==1){
				joueur[currentPlayer].win++;
				AffichageWin(carte, *score);
				printf("\nCHANGEMENT DE COULEUR DU BUT\n");
				printf("[0] Suivant\n");
				scanf("%d", &k);
			}
			currentPlayer=0;
			j++;
			while(joueur[currentPlayer].ordre!=j){
				currentPlayer++;
			}
			if(tour[color[i]].End!=1){
				if(currentPlayer==carte->nbJoueur-1){
					AffichageLose(carte);
					printf("\nCHANGEMENT DE COULEUR DU BUT\n");
				}else{
					AffichageLose(carte);
					printf("\nAU TOUR DU JOUEUR %d\n", currentPlayer+1);
				}
				printf("[0] Suivant\n");
				scanf("%d", &k);
			}
			// Definition de la carte a utiliser a chaque tour (changement de couleur)
			if(choix.Grille>3){
				k=carte->nbJoueur;
				GrilleDefinie(choix, carte, Bender, WallE, R2D2, Marvin);
				*carte=mapEdit[choix.Grille];
				carte->nbJoueur=k;
				Bender->x=temp[0].x;
				Bender->y=temp[0].y;
				WallE->x=temp[1].x;
				WallE->y=temp[1].y;
				R2D2->x=temp[2].x;
				R2D2->y=temp[2].y;
				Marvin->x=temp[3].x;
				Marvin->y=temp[3].y;
			}else{
				GrilleDefinie(choix, carte, Bender, WallE, R2D2, Marvin);
			}
		}while((j<carte->nbJoueur)&&(tour[color[i]].End!=1));
	}
	OUT:
	system("clear");
	int max=joueur[0].win;
    for(i=0;i<carte->nbJoueur;i++){
    	if (joueur[i].win>max)
        	max=joueur[i].win;
    }
    k=0;
	while(joueur[k].win!=max){
		k++;
	}
	printf("$ $ $ $ $ $ $ $ $\n");
	printf("$ FIN DE PARTIE $\n");
	printf("$ $ $ $ $ $ $ $ $\n\n");
	for(i=0;i<carte->nbJoueur;i++){
		printf("Joueur %d : %d pt(s)\n", i+1, joueur[i].win);
	}
	printf("\nJoueur %d est le gagnant\n", k+1);
	printf("\n[0] Suivant\n");
	scanf("%d", &k);
}