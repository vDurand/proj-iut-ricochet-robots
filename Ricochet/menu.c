#include "ricochet.h"

void Home(Choix* choix){
	do{
		system("clear");
		printf("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n");
		printf("#                                                                                     #\n");
  		printf("#%s  _|_|_|    _|                                _|                    _|               %s#\n", CYAN, NORMAL);
	 	printf("#%s  _|    _|        _|_|_|    _|_|      _|_|_|  _|_|_|      _|_|    _|_|_|_|    _|_|_| %s#\n", CYAN, NORMAL);
	 	printf("#%s  _|_|_|    _|  _|        _|    _|  _|        _|    _|  _|_|_|_|    _|      _|_|     %s#\n", CYAN, NORMAL);
	 	printf("#%s  _|    _|  _|  _|        _|    _|  _|        _|    _|  _|          _|          _|_| %s#\n", CYAN, NORMAL);
	 	printf("#%s  _|    _|  _|    _|_|_|    _|_|      _|_|_|  _|    _|    _|_|_|      _|_|  _|_|_|   %s#\n", CYAN, NORMAL);
	 	printf("#                                                                                     #\n");
	 	printf("#%s            _|_|_|              _|                    _|                             %s#\n", CYAN, NORMAL);
	 	printf("#%s            _|    _|    _|_|    _|_|_|      _|_|    _|_|_|_|    _|_|_|               %s#\n", CYAN, NORMAL);
	 	printf("#%s            _|_|_|    _|    _|  _|    _|  _|    _|    _|      _|_|                   %s#\n", CYAN, NORMAL);
	 	printf("#%s            _|    _|  _|    _|  _|    _|  _|    _|    _|          _|_|               %s#\n", CYAN, NORMAL);
	 	printf("#%s            _|    _|    _|_|    _|_|_|      _|_|        _|_|  _|_|_|                 %s#\n", CYAN, NORMAL);
	 	printf("#                                                                                     #\n");
		printf("#                                                                                     #\n");
		printf("#                                [1] Carte aleatoire                                  #\n");
		printf("#                                [2] Carte predefinie                                 #\n");
		printf("#                                [3] Multijoueur                                      #\n");
		printf("#                                [4] Creation de cartes                               #\n");
		printf("#                                [5] High Scores                                      #\n");
		printf("#                                [0] Quitter                                          #\n");
		printf("#                                                                                     #\n");
		printf("# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n");
		scanf("%d", &choix->Menu);
	}while((choix->Menu!=0)&&(choix->Menu!=1)&&(choix->Menu!=2)&&(choix->Menu!=3)&&(choix->Menu!=4)&&(choix->Menu!=5));
}

void Menu2(Choix* choix){
	do{
		system("clear");
		printf("CARTES PREDEFINIES:\n");
		printf("[1] Easy\n");
		printf("[2] Medium\n");
		printf("[3] Hard\n\n");
		printf("\n\nCARTES CREES:");
		printf("\n[4] Carte 1\n[5] Carte 2\n[6] Carte 3\n\n\n");
		printf("[0] Retour\n");
		scanf("%d", &choix->Grille);
	}while((choix->Grille>6));
}

void Menu3(Choix* choix, Carte* carte){
	do{
		system("clear");
		printf("CARTES PREDEFINIES:\n");
		printf("[1] Easy\n");
		printf("[2] Medium\n");
		printf("[3] Hard\n\n");
		printf("\n\nCARTES CREES:");
		printf("\n[4] Carte 1\n[5] Carte 2\n[6] Carte 3\n\n\n");
		printf("[0] Retour\n");
		scanf("%d", &choix->Grille);
	}while((choix->Grille>6));
	do{
		system("clear");
		printf("Nombre de joueurs (2-10):\n");
		scanf("%d", &carte->nbJoueur);
	}while((carte->nbJoueur>10)||(carte->nbJoueur<2));
}

void Menu4(Choix* choix){
	do{
		system("clear");
		printf("Choisir sur quelle carte enregistrer votre création\n");
		printf("/!\\ Enregistrer sur une carte déjà existante l'ecrasera /!\\ \n");
		printf("\n\nCarte Solo:\n");
		printf("\n[1] Carte 1\n[2] Carte 2\n[3] Carte 3\n");
		printf("\n\nCarte Multi:\n");
		printf("\n[4] Carte 1\n[5] Carte 2\n[6] Carte 3\n");
		printf("\n\n\n[0] Retour\n");
		scanf("%d", &choix->Grille);
	}while(choix->Grille>6);
}

void Menu5(){
	system("clear");
	int i,j;
	int nbScore=0;
	char contenu[1024];
	int hiScore[1024];
	FILE *save;
	save = fopen("save.txt","r"); /*ouverture du fichier save en read*/
	fscanf(save,"%s", contenu); /*lecture du fichier entier*/
	// calcul du nombre de scores
	for(i=0;i<=(strlen(contenu));i++){
		if(contenu[i]=='.')
			nbScore++;
	}
	j=2;
	for(i=0;i<=nbScore-1;i++){
		fseek(save, j, SEEK_SET); /*position du curseur de lecture*/
		fscanf(save,"%d", &hiScore[i]); /*lecture score*/
		// deplacement du curseur en fonction de la taille du score
		if(hiScore[i]<10){
			j=j+2;
		}
		if((hiScore[i]>9)&&(hiScore[i]<100)){
			j=j+3;
		}
		if((hiScore[i]>99)&&(hiScore[i]<1000)){
			j=j+4;
		}
	}
	fclose(save); /*done!*/
	croissant(nbScore, hiScore);
	printf("========================\n");
	printf("||     HIGH SCORE:    ||\n");
	printf("========================\n");
	printf("|\n");
	if(nbScore>1){
		printf("| %s1er : %d%s\n", GREEN, hiScore[0], NORMAL);
		for(i=1;i<nbScore-1;i++){
			printf("| %de : %d\n", i+1, hiScore[i]);
		}
		printf("| %s%de : %d%s\n", RED, nbScore, hiScore[nbScore-1], NORMAL);
	}
	if(nbScore==1){
		printf("| %s1er : %d%s\n", GREEN, hiScore[0], NORMAL);
	}
	if(nbScore==0){
		printf("| %sNO RESULT%s\n", RED, NORMAL);
	}
	printf("|\n");
	printf("----------------------\n");
}

void croissant(int m, int t[]){
	// Fonction rangeant les elements d'un tableau dans l'ordre croissant
	int i,z;
	int inverse;
	
	do{
		inverse=0;
		for(i=0;i<m-1;i++){
			if(t[i]>t[i+1]){
				z=t[i+1];
				t[i+1]=t[i];
				t[i]=z;
				inverse=1;
			}
		}
	}while(inverse==1);
}