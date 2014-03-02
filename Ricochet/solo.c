#include "ricochet.h"

void Play(Carte* map, Position* Bender, Position* WallE, Position* R2D2, Position* Marvin, int* score){

	int nRobot;
	char move;
	Round tour[4];
	// Booleen 1 = tour gagne | 0 = pas encore gagne
	tour[0].End=0;
	tour[1].End=0;
	tour[2].End=0;
	tour[3].End=0;

	do{
		while(tour[0].End!=1){
			nRobot=0;
			tour[0].End=0;
			do{
				AffichageGrille(map, *Bender, *WallE, *R2D2, *Marvin);
				AffichageManette(&move, *score, nRobot);
			}while((move!='z')&&(move!='q')&&(move!='s')&&(move!='d')&&(move!='p')&&(move!='m'));
			if(move=='p'){goto LEAVE;}
			if(move=='m'){break;}
			Deplacement(map, move, Bender);
			(*score)++;
			if((Bender->y==map->Arrive.y)&&(Bender->x==map->Arrive.x)){
				tour[0].End=1;
			}
		}
		while(tour[1].End!=1){
			nRobot=1;
			tour[1].End=0;
			do{
				AffichageGrille(map, *Bender, *WallE, *R2D2, *Marvin);
				AffichageManette(&move, *score, nRobot);
			}while((move!='z')&&(move!='q')&&(move!='s')&&(move!='d')&&(move!='p')&&(move!='m'));
			if(move=='p'){goto LEAVE;}
			if(move=='m'){break;}
			Deplacement(map, move, WallE);
			(*score)++;
			if((WallE->y==map->Arrive.y)&&(WallE->x==map->Arrive.x)){
				tour[1].End=1;
			}
		}
		while(tour[2].End!=1){
			nRobot=2;
			tour[2].End=0;
			do{
				AffichageGrille(map, *Bender, *WallE, *R2D2, *Marvin);
				AffichageManette(&move, *score, nRobot);
			}while((move!='z')&&(move!='q')&&(move!='s')&&(move!='d')&&(move!='p')&&(move!='m'));
			if(move=='p'){goto LEAVE;}
			if(move=='m'){break;}
			Deplacement(map, move, R2D2);
			(*score)++;
			if((R2D2->y==map->Arrive.y)&&(R2D2->x==map->Arrive.x)){
				tour[2].End=1;
			}
		}
		while(tour[3].End!=1){
			nRobot=3;
			tour[3].End=0;
			do{
				AffichageGrille(map, *Bender, *WallE, *R2D2, *Marvin);
				AffichageManette(&move, *score, nRobot);
			}while((move!='z')&&(move!='q')&&(move!='s')&&(move!='d')&&(move!='p')&&(move!='m'));
			if(move=='p'){goto LEAVE;}
			if(move=='m'){break;}
			Deplacement(map, move, Marvin);
			(*score)++;
			if((Marvin->y==map->Arrive.y)&&(Marvin->x==map->Arrive.x)){
				tour[3].End=1;
			}
		}
	}while((tour[0].End!=1)||(tour[1].End!=1)||(tour[2].End!=1)||(tour[3].End!=1));
	
	LEAVE:
	if(move=='p'){*score=0;}
}

void HIsave(int score){
	FILE *save;
	save = fopen("save.txt","a+"); /*ouverture du fichier save en append*/
	fprintf(save,".%d", score); /*ajoute*/
	fclose(save); /*done!*/
}

void HIclear(){
	FILE *save;
	save = fopen("save.txt","w"); /*ouverture du fichier save en write*/
	fprintf(save,"%d", 0); /*ecrase*/
	fclose(save); /*done!*/
}