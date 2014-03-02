#include "ricochet.h"

void WallMove(Carte* carte, Position* curseur, Wall Mur){
	int i;
	// Efface l'ancien mur
	if(Mur.dir=='v'){
		if(Mur.move=='e'){
			for(i=0;i<Mur.size+2;i++){
				carte->Grille[(curseur->y)+i][curseur->x]=' ';
			}
		}else{
			if(curseur->y==(33-Mur.size)){
				for(i=0;i<Mur.size-1;i++){
					carte->Grille[(curseur->y)+i][curseur->x]=' ';
				}
			}else{
				for(i=0;i<Mur.size;i++){
					carte->Grille[(curseur->y)+i][curseur->x]=' ';
				}
			}
		}
		if(curseur->y==0){
			carte->Grille[curseur->y][curseur->x]='#';
		}
	}
	if(Mur.dir=='h'){
		if(Mur.move=='e'){
			for(i=0;i<Mur.size+2;i++){
				carte->Grille[curseur->y][(curseur->x)+i]=' ';
			}
		}else{
			if(curseur->x==(33-Mur.size)){
				for(i=0;i<Mur.size-1;i++){
					carte->Grille[curseur->y][(curseur->x)+i]=' ';
				}
			}else{
				for(i=0;i<Mur.size;i++){
					carte->Grille[curseur->y][(curseur->x)+i]=' ';
				}
			}
		}
		if(curseur->x==0){
			carte->Grille[curseur->y][curseur->x]='#';
		}
	}
	// Deplace le point de depart du mur
	switch(Mur.move){
			case 'z':
				if(Mur.dir=='v'){
					if((curseur->y)>1)
						(curseur->y)-=2;
				}
				if(Mur.dir=='h'){
					if((curseur->y)>2)
						(curseur->y)-=2;
				}
			break;
			case 's':
				if(Mur.dir=='v'){
					if((curseur->y)<(32-Mur.size))
						(curseur->y)+=2;
				}
				if(Mur.dir=='h'){
					if((curseur->y)<30)
						(curseur->y)+=2;
				}
			break;
			case 'q':
				if(Mur.dir=='v'){
					if((curseur->x)>2)
						(curseur->x)-=2;
				}
				if(Mur.dir=='h'){
					if((curseur->x)>1)
						(curseur->x)-=2;
				}
			break;
			case 'd':
				if(Mur.dir=='h'){
					if((curseur->x)<(32-Mur.size))
						(curseur->x)+=2;
				}
				if(Mur.dir=='v'){
					if((curseur->x)<30)
						(curseur->x)+=2;
				}
			break;
	}
}

void WallSize(Wall* Mur){
	switch(Mur->move){
		// Augmente la taille du mur
			case 'a':
				(Mur->size)++;
				(Mur->size)++;
			break;
		// Diminue la taille du mur
			case 'e':
				if(Mur->size>3){
					(Mur->size)--;
					(Mur->size)--;
				}
			break;
	}
}

void CibleMove(Carte* carte, char move, Position* curseur){
	switch(move){
		case 'z':
			if(((curseur->y)>1)&&(carte->Grille[(curseur->y)-2][curseur->x]==' ')){
				(curseur->y)-=2;
			}
		break;
		case 's':
			if(((curseur->y)<31)&&(carte->Grille[(curseur->y)+2][curseur->x]==' ')){
				(curseur->y)+=2;
			}
		break;
		case 'q':
			if(((curseur->x)>1)&&(carte->Grille[curseur->y][(curseur->x)-2]==' ')){
				(curseur->x)-=2;
			}
		break;
		case 'd':
			if(((curseur->x)<31)&&(carte->Grille[curseur->y][(curseur->x)+2]==' ')){
				(curseur->x)+=2;
			}
		break;
	}
}

void Edit(Carte* carte, Position* bender, Position* wallE, Position* r2d2, Position* marvin){
	int i,j,n;
	Wall Mur;
	char move;
	char temp;
	Position curseur;
	Position tempCur;
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
    // Position initiale des robots
    bender->y=99;
    bender->x=99;
    wallE->y=99;
    wallE->x=99;
    r2d2->y=99;
    r2d2->x=99;
    marvin->y=99;
    marvin->x=99;
    
    // Position Arrive
    carte->Arrive.x=99;
    carte->Arrive.y=99;
    for(i=0;i<4;i++){
    	carte->Cible[i].y=99;
    	carte->Cible[i].x=99;
    }
    
	// Placement des murs
	do{
		
		do{
			AffichageGrille(carte, *bender, *wallE, *r2d2, *marvin);
			printf("\nChoix de l'orientation du mur :\n");
			printf("[v] Mur Vertical              [h] Mur Horizontal              [p] Mettre les Robots\n");
			scanf("%c", &Mur.dir);
		}while(Mur.dir!='v'&&Mur.dir!='h'&&Mur.dir!='p');
		if(Mur.dir!='p'){
			curseur.x=2;
			curseur.y=2;
			Mur.size=3;
			carte->Grille[curseur.y][curseur.x]='#';
			do{
				do{
					if(Mur.dir=='v'){
						for(i=0;i<Mur.size;i++){
							carte->Grille[(curseur.y)+i][curseur.x]='#';
						}
					}
					if(Mur.dir=='h'){
						for(i=0;i<Mur.size;i++){
							carte->Grille[curseur.y][(curseur.x)+i]='#';
						}
					}
					AffichageGrille(carte, *bender, *wallE, *r2d2, *marvin);
					printf("\nTaille du mur :\n");
					printf("[a] Augmenter              [e] Diminuer\n");
					printf("\n\nDeplacer le mur :\n");
					printf("\n      ↑\n     [z]\n ← [q] [d]→  \n     [s]\n      ↓                                          [p] Nouveau Mur\n\n");
					scanf("%c", &Mur.move);
				}while(Mur.move!='a'&&Mur.move!='e'&&Mur.move!='z'&&Mur.move!='q'&&Mur.move!='s'&&Mur.move!='d'&&Mur.move!='p');	
				if(Mur.move=='a'||Mur.move=='e'){
					WallSize(&Mur);
				}
				if(Mur.move!='p'){
					WallMove(carte, &curseur, Mur);
				}
			}while(Mur.move!='p');
		}
	}while(Mur.dir!='p');
	// Placement des robots
	if(carte->nbJoueur>1){
		n=8;
	}else{
		n=5;
	}
	for(i=0;i<n;i++){
		curseur.x=1;
		curseur.y=1;
		tempCur.x=99;
		tempCur.y=99;
		move='x';
		do{
			carte->Grille[tempCur.y][tempCur.x]=' ';
			if(i==0){
				bender->y=curseur.x;
				bender->x=curseur.y;
			}
			if(i==1){
				wallE->y=curseur.x;
				wallE->x=curseur.y;
			}
			if(i==2){
				r2d2->y=curseur.x;
				r2d2->x=curseur.y;
			}
			if(i==3){
				marvin->y=curseur.x;
				marvin->x=curseur.y;
			}
			if(carte->nbJoueur==1){
				if(i==4){
					carte->Arrive.y=curseur.x;
					carte->Arrive.x=curseur.y;
				}
			}else{
				if(i>3){
					carte->Cible[i-4].y=curseur.x;
					carte->Cible[i-4].x=curseur.y;
				}
			}
			
			do{
				AffichageGrille(carte, *bender, *wallE, *r2d2, *marvin);
				printf("\nDeplacer le robot :\n");
				if(i==3){
					printf("\n      ↑\n     [z]\n ← [q] [d]→  \n     [s]\n      ↓                                          [p] Placer Arrivee\n\n");
				}else{
					if(i==4){
						printf("\n      ↑\n     [z]\n ← [q] [d]→  \n     [s]\n      ↓                                          [p] Terminer et sauvegarder\n\n");
					}else{
						printf("\n      ↑\n     [z]\n ← [q] [d]→  \n     [s]\n      ↓                                          [p] Robot Suivant\n\n");
					}
				}
				scanf("%c", &move);
			}while(move!='a'&&move!='e'&&move!='z'&&move!='q'&&move!='s'&&move!='d'&&move!='p');	
			tempCur.x=curseur.x;
			tempCur.y=curseur.y;
			CibleMove(carte, move, &curseur);
		}while(move!='p');
	}
}