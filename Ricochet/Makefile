all: Ricochet
Ricochet	: main.o menu.o carte.o deplacement.o affichage.o aleatoire.o editor.o solo.o multi.o
	gcc main.o menu.o carte.o deplacement.o affichage.o aleatoire.o solo.o editor.o multi.o -o Ricochet
main.o	: main.c ricochet.h
	gcc -c main.c
menu.o	: menu.c ricochet.h
	gcc -c menu.c
carte.o	: carte.c ricochet.h
	gcc -c carte.c
deplacement.o	: deplacement.c ricochet.h
	gcc -c deplacement.c
affichage.o	: affichage.c ricochet.h
	gcc -c affichage.c
aleatoire.o	: aleatoire.c ricochet.h
	gcc -c aleatoire.c
solo.o	: solo.c ricochet.h
	gcc -c solo.c
editor.o	: editor.c ricochet.h
	gcc -c editor.c
multi.o	: multi.c ricochet.h
	gcc -c multi.c