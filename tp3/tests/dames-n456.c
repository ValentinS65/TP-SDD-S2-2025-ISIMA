#include <stdio.h>
#include <stdlib.h>
#include "dames.h"


int main()
{

	int n=7;
	int * placement=(int*)malloc(n*sizeof(int));

	liste_solutions * solutions=addAllSolutions(NULL, placement,0,n);
	if (nbSolutions(solutions)!=40){
		return 1;
	}

	n=6;
	solutions=addAllSolutions(NULL, placement,0,n);
	if (nbSolutions(solutions)!=4){
		return 1;
	}

	n=5;
	solutions=addAllSolutions(NULL, placement,0,n);
	if (nbSolutions(solutions)!=10){
		return 1;
	}

	n=4;
	solutions=addAllSolutions(NULL, placement,0,n);
	if (nbSolutions(solutions)!=2){
		return 1;
	}

	return 0;

}
