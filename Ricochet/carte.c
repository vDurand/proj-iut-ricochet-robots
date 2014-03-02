#include "ricochet.h"

void GrilleDefinie(Choix choix, Carte* carte, Position* bender, Position* wallE, Position* r2d2, Position* marvin){
	int i,j;

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

	// Affichage MAP1
    if(choix.Grille==1){
        // Insertion des murs verticaux de la grille prédéfinie.
        carte->Grille[1][16]=carte->Grille[2][16]=carte->Grille[30][16]=carte->Grille[31][16]='#';

        //Insertion des murs horizontaux de la grille prédéfinie.
        carte->Grille[16][1]=carte->Grille[16][2]=carte->Grille[17][30]=carte->Grille[17][31]='#';

        // Position initiale des robots
        bender->y=1;
        bender->x=1;
        wallE->y=31;
        wallE->x=1;
        r2d2->y=1;
        r2d2->x=31;
        marvin->y=31;
        marvin->x=31;
        
        // Position Arrive
        if(carte->nbJoueur==1){
            carte->Arrive.x=15;
            carte->Arrive.y=1;
        }
        if(carte->nbJoueur>1){
            carte->Cible[0].x=15;
            carte->Cible[0].y=1;
            carte->Cible[1].x=17;
            carte->Cible[1].y=1;
            carte->Cible[2].x=16;
            carte->Cible[2].y=31;
            carte->Cible[3].x=18;
            carte->Cible[3].y=31;
        }
    }


	// Affichage MAP2
    if(choix.Grille==2){
        // Insertion des murs verticaux de la grille prédéfinie.
        carte->Grille[1][8]=carte->Grille[2][8]='#';
        carte->Grille[1][24]=carte->Grille[2][24]='#';
        carte->Grille[2][26]=carte->Grille[3][26]=carte->Grille[4][26]='#';
        carte->Grille[4][12]=carte->Grille[5][12]=carte->Grille[6][12]='#';
        carte->Grille[4][20]=carte->Grille[5][20]=carte->Grille[6][20]='#';
        carte->Grille[8][6]=carte->Grille[9][6]=carte->Grille[10][6]='#';
        carte->Grille[10][14]=carte->Grille[11][14]=carte->Grille[12][14]='#';
        carte->Grille[10][28]=carte->Grille[11][28]=carte->Grille[12][28]='#';
        carte->Grille[12][2]=carte->Grille[13][2]=carte->Grille[14][2]='#';
        carte->Grille[12][24]=carte->Grille[13][24]=carte->Grille[14][24]='#';
        carte->Grille[14][14]=carte->Grille[15][14]=carte->Grille[16][14]='#';
        carte->Grille[14][18]=carte->Grille[15][18]=carte->Grille[16][18]='#';
        carte->Grille[16][14]=carte->Grille[17][14]=carte->Grille[18][14]='#';
        carte->Grille[16][18]=carte->Grille[17][18]=carte->Grille[18][18]='#';
        carte->Grille[18][8]=carte->Grille[19][8]=carte->Grille[20][8]='#';
        carte->Grille[18][26]=carte->Grille[19][26]=carte->Grille[20][26]='#';
        carte->Grille[20][12]=carte->Grille[21][12]=carte->Grille[22][12]='#';
        carte->Grille[24][16]=carte->Grille[25][16]=carte->Grille[26][16]='#';
        carte->Grille[24][18]=carte->Grille[25][18]=carte->Grille[26][18]='#';
        carte->Grille[26][4]=carte->Grille[27][4]=carte->Grille[28][4]='#';
        carte->Grille[26][28]=carte->Grille[27][28]=carte->Grille[28][28]='#';
        carte->Grille[28][8]=carte->Grille[29][8]=carte->Grille[30][8]='#';
        carte->Grille[28][24]=carte->Grille[29][24]=carte->Grille[30][24]='#';
        carte->Grille[30][10]=carte->Grille[31][10]=carte->Grille[32][10]='#';
        carte->Grille[30][28]=carte->Grille[31][28]=carte->Grille[32][28]='#';

        //Insertion des murs horizontaux de la grille prédéfinie.
        carte->Grille[2][26]=carte->Grille[2][27]=carte->Grille[2][28]='#';
        carte->Grille[2][26]=carte->Grille[2][27]=carte->Grille[2][28]='#';
        carte->Grille[2][26]=carte->Grille[2][27]=carte->Grille[2][28]='#';
        carte->Grille[6][10]=carte->Grille[6][11]=carte->Grille[6][12]='#';
        carte->Grille[6][18]=carte->Grille[6][19]=carte->Grille[6][20]='#';
        carte->Grille[8][4]=carte->Grille[8][5]=carte->Grille[8][6]='#';
        carte->Grille[8][30]=carte->Grille[8][31]=carte->Grille[8][32]='#';
        carte->Grille[10][0]=carte->Grille[10][1]=carte->Grille[10][2]='#';
        carte->Grille[12][2]=carte->Grille[12][3]=carte->Grille[12][4]='#';
        carte->Grille[12][14]=carte->Grille[12][15]=carte->Grille[12][16]='#';
        carte->Grille[12][28]=carte->Grille[12][29]=carte->Grille[12][30]='#';
        carte->Grille[12][22]=carte->Grille[12][23]=carte->Grille[12][24]='#';
        carte->Grille[14][14]=carte->Grille[14][15]=carte->Grille[14][16]='#';
        carte->Grille[14][16]=carte->Grille[14][17]=carte->Grille[14][18]='#';
        carte->Grille[18][14]=carte->Grille[18][15]=carte->Grille[18][16]='#';
        carte->Grille[18][16]=carte->Grille[18][17]=carte->Grille[18][18]='#';
        carte->Grille[18][24]=carte->Grille[18][25]=carte->Grille[18][26]='#';
        carte->Grille[20][8]=carte->Grille[20][9]=carte->Grille[20][10]='#';
        carte->Grille[20][12]=carte->Grille[20][13]=carte->Grille[20][14]='#';
        carte->Grille[20][30]=carte->Grille[20][31]=carte->Grille[20][32]='#';
        carte->Grille[22][0]=carte->Grille[22][1]=carte->Grille[22][2]='#';
        carte->Grille[24][14]=carte->Grille[24][15]=carte->Grille[24][16]='#';
        carte->Grille[24][18]=carte->Grille[24][19]=carte->Grille[24][20]='#';
        carte->Grille[26][2]=carte->Grille[26][3]=carte->Grille[26][4]='#';
        carte->Grille[28][28]=carte->Grille[28][29]=carte->Grille[28][30]='#';
        carte->Grille[30][6]=carte->Grille[30][7]=carte->Grille[30][8]='#';
        carte->Grille[30][22]=carte->Grille[30][23]=carte->Grille[30][24]='#';

        // Position initiale des robots
        bender->y=10;
        bender->x=10;
        wallE->y=5;
        wallE->x=5;
        r2d2->y=12;
        r2d2->x=12;
        marvin->y=25;
        marvin->x=25;
        
        // Position Arrive
        if(carte->nbJoueur==1){
            carte->Arrive.x=1;
            carte->Arrive.y=1;
        }
        if(carte->nbJoueur>1){
            carte->Cible[0].x=1;
            carte->Cible[0].y=1;
            carte->Cible[1].x=1;
            carte->Cible[1].y=31;
            carte->Cible[2].x=31;
            carte->Cible[2].y=1;
            carte->Cible[3].x=31;
            carte->Cible[3].y=31;
        }
    }

	// Affichage MAP3
	if(choix.Grille==3){
		// Insertion des murs verticaux de la grille prédéfinie.
        carte->Grille[1][10]=carte->Grille[2][10]=carte->Grille[2][14]=carte->Grille[3][14]='#';
        carte->Grille[4][14]=carte->Grille[1][26]=carte->Grille[2][26]=carte->Grille[6][6]='#';
        carte->Grille[7][6]=carte->Grille[8][6]=carte->Grille[9][6]=carte->Grille[10][6]='#';
        carte->Grille[10][2]=carte->Grille[11][2]=carte->Grille[12][2]=carte->Grille[8][16]='#';
        carte->Grille[9][16]=carte->Grille[10][16]=carte->Grille[6][18]=carte->Grille[7][18]='#';
        carte->Grille[8][18]=carte->Grille[14][14]=carte->Grille[15][14]=carte->Grille[16][14]='#';
        carte->Grille[17][14]=carte->Grille[18][14]=carte->Grille[14][18]=carte->Grille[15][18]='#';
        carte->Grille[16][18]=carte->Grille[17][18]=carte->Grille[18][18]=carte->Grille[12][24]='#';
        carte->Grille[13][24]=carte->Grille[14][24]=carte->Grille[10][28]=carte->Grille[11][28]='#';
        carte->Grille[12][28]=carte->Grille[16][12]=carte->Grille[17][12]=carte->Grille[18][12]='#';
        carte->Grille[16][26]=carte->Grille[17][26]=carte->Grille[18][26]=carte->Grille[18][6]='#';
        carte->Grille[19][6]=carte->Grille[20][6]=carte->Grille[20][12]=carte->Grille[21][12]='#';
        carte->Grille[22][12]=carte->Grille[24][10]=carte->Grille[25][10]=carte->Grille[26][10]='#';
        carte->Grille[24][18]=carte->Grille[25][18]=carte->Grille[26][18]=carte->Grille[24][28]='#';
        carte->Grille[25][28]=carte->Grille[26][28]=carte->Grille[30][6]=carte->Grille[31][6]='#';
        carte->Grille[30][16]=carte->Grille[31][16]=carte->Grille[28][24]=carte->Grille[29][24]='#';
        carte->Grille[30][24]=carte->Grille[30][28]=carte->Grille[31][28]='#';

        //Insertion des murs horizontaux de la grille prédéfinie.
        carte->Grille[4][1]=carte->Grille[4][2]=carte->Grille[24][1]=carte->Grille[24][2]='#';
        carte->Grille[12][3]=carte->Grille[12][4]=carte->Grille[8][4]=carte->Grille[8][5]='#';
        carte->Grille[8][7]=carte->Grille[8][8]=carte->Grille[2][15]=carte->Grille[2][16]='#';
        carte->Grille[6][19]=carte->Grille[6][20]=carte->Grille[8][30]=carte->Grille[8][31]='#';
        carte->Grille[10][14]=carte->Grille[10][15]=carte->Grille[12][22]=carte->Grille[12][23]='#';
        carte->Grille[12][26]=carte->Grille[12][27]=carte->Grille[14][15]=carte->Grille[14][16]='#';
        carte->Grille[14][17]=carte->Grille[18][15]=carte->Grille[18][16]=carte->Grille[18][17]='#';
        carte->Grille[16][10]=carte->Grille[16][11]=carte->Grille[16][25]=carte->Grille[16][24]='#';
        carte->Grille[16][30]=carte->Grille[16][31]=carte->Grille[20][7]=carte->Grille[20][8]='#';
        carte->Grille[20][13]=carte->Grille[20][14]=carte->Grille[26][11]=carte->Grille[26][12]='#';
        carte->Grille[24][19]=carte->Grille[24][20]=carte->Grille[24][26]=carte->Grille[24][27]='#';
        carte->Grille[30][22]=carte->Grille[30][23]='#';

        // Position initiale des robots
        bender->y=11;
        bender->x=9;
        wallE->y=21;
        wallE->x=5;
        r2d2->y=13;
        r2d2->x=23;
        marvin->y=27;
        marvin->x=27;

        // Position Arrive
        if(carte->nbJoueur==1){
            carte->Arrive.x=31;
            carte->Arrive.y=13;
        }
        if(carte->nbJoueur>1){
            carte->Cible[0].x=1;
            carte->Cible[0].y=1;
            carte->Cible[1].x=3;
            carte->Cible[1].y=11;
            carte->Cible[2].x=15;
            carte->Cible[2].y=19;
            carte->Cible[3].x=31;
            carte->Cible[3].y=31;
        }
	}
}