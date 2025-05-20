#ifndef dames_h
#define dames_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct liste_solutions{
	int * placement;
	struct liste_solutions * next;
} liste_solutions;

liste_solutions *  addSolution(liste_solutions * ,int *,int );

void displayGame(int* , int );

int casePossible(int * ,int ,int,int );

liste_solutions *  addAllSolutions(liste_solutions * , int * ,int ,int );

void test_casePossible();

int nbSolutions(liste_solutions*);

void displaySolutions(liste_solutions*,int );
void freeSolutions(liste_solutions *);
#endif