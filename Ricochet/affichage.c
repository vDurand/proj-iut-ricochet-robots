#include "ricochet.h"

void AffichageGrille(Carte* carte, Position bender, Position wallE, Position r2d2, Position marvin){
	int i,j;
	system("clear");
	carte->Grille[bender.x][bender.y]='B';
	carte->Grille[wallE.x][wallE.y]='W';
	carte->Grille[r2d2.x][r2d2.y]='R';
	carte->Grille[marvin.x][marvin.y]='M';
	if(carte->nbJoueur==1){
		carte->Grille[carte->Arrive.x][carte->Arrive.y]='$';
		for(i=0; i<33; i++){
			for(j=0; j<33; j++){
				if(j==32){
					printf("%s%2c\n", NORMAL, carte->Grille[i][j]);
				}
				else if((j==carte->Arrive.y)&&(i==carte->Arrive.x)){
					printf("%s%2c", RED, carte->Grille[i][j]);
				}
				else if((j==bender.y)&&(i==bender.x)){
					printf("%s%2c", GREEN, carte->Grille[i][j]);
				}
				else if((j==wallE.y)&&(i==wallE.x)){
					printf("%s%2c", BLUE, carte->Grille[i][j]);
				}
				else if((j==r2d2.y)&&(i==r2d2.x)){
					printf("%s%2c", YELLOW, carte->Grille[i][j]);
				}
				else if((j==marvin.y)&&(i==marvin.x)){
					printf("%s%2c", MAG, carte->Grille[i][j]);
				}
				else{
					printf("%s%2c", NORMAL, carte->Grille[i][j]);
				}
			}
		}
	}
	if(carte->nbJoueur>1){
		for(i=0;i<4;i++){
			carte->Grille[carte->Cible[i].x][carte->Cible[i].y]='$';
		}
		for(i=0; i<33; i++){
			for(j=0; j<33; j++){
				if(j==32){
					printf("%s%2c\n", NORMAL, carte->Grille[i][j]);
				}
				else if((j==carte->Cible[0].y)&&(i==carte->Cible[0].x)){
					printf("%s%2c", GREEN, carte->Grille[i][j]);
				}
				else if((j==carte->Cible[1].y)&&(i==carte->Cible[1].x)){
					printf("%s%2c", BLUE, carte->Grille[i][j]);
				}
				else if((j==carte->Cible[2].y)&&(i==carte->Cible[2].x)){
					printf("%s%2c", YELLOW, carte->Grille[i][j]);
				}
				else if((j==carte->Cible[3].y)&&(i==carte->Cible[3].x)){
					printf("%s%2c", MAG, carte->Grille[i][j]);
				}
				else if((j==bender.y)&&(i==bender.x)){
					printf("%s%2c", GREEN, carte->Grille[i][j]);
				}
				else if((j==wallE.y)&&(i==wallE.x)){
					printf("%s%2c", BLUE, carte->Grille[i][j]);
				}
				else if((j==r2d2.y)&&(i==r2d2.x)){
					printf("%s%2c", YELLOW, carte->Grille[i][j]);
				}
				else if((j==marvin.y)&&(i==marvin.x)){
					printf("%s%2c", MAG, carte->Grille[i][j]);
				}
				else{
					printf("%s%2c", NORMAL, carte->Grille[i][j]);
				}
			}
		}
	}
}

void AffichageWin(Carte* carte, int score){
	int i,j;
	// Configuration de la carte WINNING
		for(i=0; i<33; i++){	
			carte->Grille[0][i]='#';
			carte->Grille[32][i]='#';
			carte->Grille[i][0]='#';
			carte->Grille[i][32]='#';
		}
		for(i=1; i<32; i++){
			for(j=1; j<32; j++)
				carte->Grille[i][j]=' ';
		}
		for(i=6; i<10; i++){
			carte->Grille[i][4]='$';
			carte->Grille[i][10]='$';
		}
		for(i=18; i<26; i++){
			carte->Grille[i][4]='$';
			carte->Grille[i][7]='$';
			carte->Grille[i][10]='$';
			carte->Grille[i][28]='$';
		}
		for(i=6; i<14; i++){
			carte->Grille[i][22]='$';
			carte->Grille[i][28]='$';
		}
		for(i=19; i<26; i++){
			carte->Grille[i][13]='$';
			carte->Grille[i][19]='$';
			carte->Grille[i][25]='$';
		}
		for(i=7; i<14; i++){
			carte->Grille[i][13]='$';
			carte->Grille[i][19]='$';
		}
		for(i=19; i<27; i++){
			carte->Grille[i][22]='$';
			carte->Grille[i][28]='$';
		}
		for(i=10; i<15; i++){
			carte->Grille[i][7]='$';
		}
		for(j=5; j<10; j++){
			carte->Grille[10][j]='$';
			carte->Grille[26][j]='$';
		}
		carte->Grille[26][7]=' ';
		for(j=14; j<19; j++){
			carte->Grille[6][j]='$';
			carte->Grille[14][j]='$';
			carte->Grille[18][j]='$';
			carte->Grille[26][j]='$';
		}
		for(j=23; j<28; j++){
			carte->Grille[14][j]='$';
		}
		carte->Grille[18][22]=carte->Grille[18][23]=carte->Grille[18][24]=carte->Grille[26][26]=carte->Grille[26][27]='$';
	// Affichage carte WIN
	system("clear");
	for(i=0; i<33; i++){
		for(j=0; j<33; j++){
			if(j==32){
				printf("%s%2c\n", NORMAL, carte->Grille[i][j]);
			}
			else{
				if(j>0&&j<32&&i>0&&i<32){
					printf("%s%2c", GREEN, carte->Grille[i][j]);
				}
				else{
					printf("%s%2c", NORMAL, carte->Grille[i][j]);
				}
			}
		}
	}
	// Affichage score
	printf("%s        SCORE : %d%s\n", RED, score, NORMAL);
}
int AffichageManette(char* move, int score, int nRobot){
	if(nRobot==0)
		printf("\n\n\n\nRobot:%s B %s                                        Score : %s%d%s\n", GREEN, NORMAL, RED , score, NORMAL);
	if(nRobot==1)
		printf("\n\n\n\nRobot:%s W %s                                        Score : %s%d%s\n", BLUE, NORMAL, RED , score, NORMAL);
	if(nRobot==2)
		printf("\n\n\n\nRobot:%s R %s                                        Score : %s%d%s\n", YELLOW, NORMAL, RED , score, NORMAL);
	if(nRobot==3)
		printf("\n\n\n\nRobot:%s M %s                                        Score : %s%d%s\n", MAG, NORMAL, RED , score, NORMAL);
	printf("\nMouvement:                                       [m] Changer Robot\n");
	printf("\n      ↑\n     [z]\n ← [q] [d]→  \n     [s]\n      ↓                                          [p] Quitter\n\n");
	*move=getchar();
	scanf("%c", move);
}

void AffichageLose(Carte* carte){
	int i,j;
	// Configuration de la carte LOSING
		for(i=0; i<33; i++){	
			carte->Grille[0][i]='#';
			carte->Grille[32][i]='#';
			carte->Grille[i][0]='#';
			carte->Grille[i][32]='#';
		}
		for(i=1; i<32; i++){
			for(j=1; j<32; j++)
				carte->Grille[i][j]=' ';
		}
		for(i=6; i<10; i++){
			carte->Grille[i][4]='$';
			carte->Grille[i][10]='$';
		}
		for(i=18; i<27; i++){
			carte->Grille[i][4]='$';
			carte->Grille[i][26]='$';
		}
		for(i=6; i<14; i++){
			carte->Grille[i][22]='$';
			carte->Grille[i][28]='$';
		}
		for(i=19; i<26; i++){
			carte->Grille[i][10]='$';
			carte->Grille[i][14]='$';
		}
		for(i=7; i<14; i++){
			carte->Grille[i][13]='$';
			carte->Grille[i][19]='$';
		}
		for(i=10; i<15; i++){
			carte->Grille[i][7]='$';
		}
		for(j=5; j<10; j++){
			carte->Grille[10][j]='$';
			carte->Grille[26][j]='$';
		}
		carte->Grille[26][9]=' ';
		for(j=14; j<19; j++){
			carte->Grille[6][j]='$';
			carte->Grille[14][j]='$';
		}
		for(j=23; j<28; j++){
			carte->Grille[14][j]='$';
		}
		for(j=11; j<14; j++){
			carte->Grille[18][j]='$';
			carte->Grille[26][j]='$';
		}
		for(j=17; j<22; j++){
			carte->Grille[18][j]='$';
			carte->Grille[26][j]='$';
		}
		for(j=24; j<29; j++){
			carte->Grille[18][j]='$';
		}
		carte->Grille[18][17]=carte->Grille[26][21]=' ';
		carte->Grille[19][17]=carte->Grille[20][17]=carte->Grille[21][17]=carte->Grille[22][18]=carte->Grille[22][19]=carte->Grille[22][20]=carte->Grille[23][21]=carte->Grille[24][21]=carte->Grille[25][21]='$';
	// Affichage carte LOSING
	system("clear");
	for(i=0; i<33; i++){
		for(j=0; j<33; j++){
			if(j==32){
				printf("%s%2c\n", NORMAL, carte->Grille[i][j]);
			}
			else{
				if(j>0&&j<32&&i>0&&i<32){
					printf("%s%2c", RED, carte->Grille[i][j]);
				}
				else{
					printf("%s%2c", NORMAL, carte->Grille[i][j]);
				}
			}
		}
	}
}