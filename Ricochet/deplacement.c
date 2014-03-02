#include "ricochet.h"

void Deplacement(Carte* carte, char move, Position* robot){
	carte->Grille[robot->x][robot->y]=' ';
	if(move=='z'){
		while((carte->Grille[(robot->x)-1][robot->y]==' ')||(carte->Grille[(robot->x)-1][robot->y]=='$')){
			robot->x=(robot->x)-1;
		}
	}
	if(move=='q'){
		while((carte->Grille[robot->x][(robot->y)-1]==' ')||(carte->Grille[robot->x][(robot->y)-1]=='$')){
			robot->y=(robot->y)-1;
		}
	}
	if (move=='d'){
		while((carte->Grille[robot->x][(robot->y)+1]==' ')||(carte->Grille[robot->x][(robot->y)+1]=='$')){
			robot->y=(robot->y)+1;
		}
	}
	if(move=='s'){
		while((carte->Grille[(robot->x)+1][robot->y]==' ')||(carte->Grille[(robot->x)+1][robot->y]=='$')){
			robot->x=(robot->x)+1;
		}
	}
}

void BotDeplacement(Carte* carte, int move, Position* robot){
	carte->Grille[robot->x][robot->y]=' ';
	if(move==0){
		while((carte->Grille[(robot->x)-1][robot->y]==' ')||(carte->Grille[(robot->x)-1][robot->y]=='$')){
			robot->x=(robot->x)-1;
		}
	}
	if(move==1){
		while((carte->Grille[robot->x][(robot->y)-1]==' ')||(carte->Grille[robot->x][(robot->y)-1]=='$')){
			robot->y=(robot->y)-1;
		}
	}
	if (move==2){
		while((carte->Grille[robot->x][(robot->y)+1]==' ')||(carte->Grille[robot->x][(robot->y)+1]=='$')){
			robot->y=(robot->y)+1;
		}
	}
	if(move==3){
		while((carte->Grille[(robot->x)+1][robot->y]==' ')||(carte->Grille[(robot->x)+1][robot->y]=='$')){
			robot->x=(robot->x)+1;
		}
	}
}