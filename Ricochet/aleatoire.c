#include "ricochet.h"

int CibleValide(Carte carte){
		if(carte.Grille[carte.Arrive.x+1][carte.Arrive.y]=='#'){
			//printf("H+1 OK\n"); 
			return 1;
		}
		if(carte.Grille[carte.Arrive.x-1][carte.Arrive.y]=='#'){
			//printf("H-1 OK\n"); 
			return 1;
		}
		if(carte.Grille[carte.Arrive.x][carte.Arrive.y+1]=='#'){
			//printf("V+1 OK\n"); 
			return 1;
		}
		if(carte.Grille[carte.Arrive.x][carte.Arrive.y-1]=='#'){
			//printf("V-1 OK\n"); 
			return 1;
		}
		else{return 0;}
}

int CarteValide(Carte* botMap, Position botRobot[]){

	Round tour[4];
	tour[0].End=0;
	tour[1].End=0;
	tour[2].End=0;
	tour[3].End=0;
	int ChoixRobot;
	int move;
	int score=0;
	srandom(time(NULL));

	do{
		ChoixRobot=(random()%4);
		move=(random()%4);
		system("clear");
		//printf("Loading...\n");
		if(ChoixRobot==0&&tour[0].End==0){
			//AffichageGrille(botMap, botRobot[0], botRobot[1], botRobot[2], botRobot[3]);
			BotDeplacement(botMap, move, &botRobot[0]);
			score++;
			printf("Loading\n");
			if((botRobot[0].y==botMap->Arrive.y)&&(botRobot[0].x==botMap->Arrive.x)){
				tour[0].End=1;
			}
		}
		if(ChoixRobot==1&&tour[1].End==0){
			//AffichageGrille(botMap, botRobot[0], botRobot[1], botRobot[2], botRobot[3]);
			BotDeplacement(botMap, move, &botRobot[1]);
			score++;
			printf("Loading.\n");
			if((botRobot[1].y==botMap->Arrive.y)&&(botRobot[1].x==botMap->Arrive.x)){
				tour[1].End=1;
			}		
		}
		if(ChoixRobot==2&&tour[2].End==0){
			//AffichageGrille(botMap, botRobot[0], botRobot[1], botRobot[2], botRobot[3]);
			BotDeplacement(botMap, move, &botRobot[2]);
			score++;
			printf("Loading..\n");
			if((botRobot[2].y==botMap->Arrive.y)&&(botRobot[2].x==botMap->Arrive.x)){
				tour[2].End=1;
			}		
		}
		if(ChoixRobot==3&&tour[3].End==0){
			//AffichageGrille(botMap, botRobot[0], botRobot[1], botRobot[2], botRobot[3]);
			BotDeplacement(botMap, move, &botRobot[3]);
			score++;
			printf("Loading...\n");
			if((botRobot[3].y==botMap->Arrive.y)&&(botRobot[3].x==botMap->Arrive.x)){
				tour[3].End=1;
			}
		}
	}while((score!=200)&&((tour[0].End!=1)||(tour[1].End!=1)||(tour[2].End!=1)||(tour[3].End!=1)));

	if((tour[0].End==1)&&(tour[1].End==1)&&(tour[2].End==1)&&(tour[3].End==1)){return 1;}
	return 0;
}

void RobotAleatoire(Carte carte, int* VerticalX, int* HorizonX){
	do{
		do{
			*VerticalX=(random()%(31-1))+1;
		}while(*VerticalX%2==0);
		do{
			*HorizonX=(random()%(31-1))+1;
		}while(*HorizonX%2==0);
	}while(carte.Grille[*HorizonX][*VerticalX]!=' ');
}

void GrilleAleatoire(Carte* carte, Position* bender, Position* wallE, Position* r2d2, Position* marvin){
	int nVertical, nHorizon, VerticalX, HorizonX;
	int i,j,compteur;
	Carte botMap;
	Position botRobot[4];
	int test=0;
	srandom(time(NULL));

	while(test!=1){
		// Creation du cadre
		for(i=0;i<33;i++){
			for(j=0;j<33;j++){
				carte->Grille[0][j]='#';
				carte->Grille[i][0]='#';
				carte->Grille[i][32]='#';
				carte->Grille[32][j]='#';
			}
		}
		// Remplissage interne blanc
		for(i=1;i<32;i++){
			for(j=1;j<32;j++){
				carte->Grille[i][j]=' ';
			}
		}
		// Insertion des murs verticaux de la grille aleatoire
		nVertical=(random()%(25-5))+5;
		compteur=0;
		do{
			do{
				VerticalX=(random()%(30-2))+2;
			}while(VerticalX%2!=0);
			do{
				HorizonX=(random()%30);
			}while(HorizonX%2!=0);
			for(i=HorizonX;i<HorizonX+3;i++){
				carte->Grille[i][VerticalX]='#';
			}
			compteur++;
		}while(compteur!=nVertical);

		// Insertion des murs horizontaux de la grille aleatoire
		nHorizon=(random()%(25-5))+5;
		compteur=0;
		do{
			do{
				HorizonX=(random()%(30-2))+2;
			}while(HorizonX%2!=0);
			do{
				VerticalX=(random()%30);
			}while(VerticalX%2!=0);
			for(i=VerticalX;i<VerticalX+3;i++){
				carte->Grille[HorizonX][i]='#';
			}
			compteur++;
		}while(compteur!=nHorizon);

	    // Position initiale des robots

		RobotAleatoire(*carte, &VerticalX, &HorizonX);
	    bender->y=VerticalX;
	    bender->x=HorizonX;
	    RobotAleatoire(*carte, &VerticalX, &HorizonX);
	    wallE->y=VerticalX;
	    wallE->x=HorizonX;
	    RobotAleatoire(*carte, &VerticalX, &HorizonX);
	    r2d2->y=VerticalX;
	    r2d2->x=HorizonX;
	    RobotAleatoire(*carte, &VerticalX, &HorizonX);
	    marvin->y=VerticalX;
	    marvin->x=HorizonX;
	    
	    // Position Arrive
	    do{
	    	RobotAleatoire(*carte, &VerticalX, &HorizonX);
	    	carte->Arrive.x=VerticalX;
	    	carte->Arrive.y=HorizonX;
	    }while(CibleValide(*carte)!=1);

	    // Copie dans bot
		for(i=0;i<33;i++){
			for(j=0;j<33;j++){
				botMap.Grille[i][j]=carte->Grille[i][j];
			}
		}
		botMap.Arrive.x=carte->Arrive.x;
		botMap.Arrive.y=carte->Arrive.y;

		botRobot[0].x=bender->x;
		botRobot[0].y=bender->y;
		botRobot[1].x=wallE->x;
		botRobot[1].y=wallE->y;
		botRobot[2].x=r2d2->x;
		botRobot[2].y=r2d2->y;
		botRobot[3].x=marvin->x;
		botRobot[3].y=marvin->y;
	    
	    test=CarteValide(&botMap, botRobot);
	}
}