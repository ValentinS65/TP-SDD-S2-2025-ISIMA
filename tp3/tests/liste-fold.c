#include <stdio.h>
#include <stdlib.h>
#include "listes.h"


int deuxsommes(int n,int p ){
	return 2*(n+p);
}

int main()
{

	list * l = listCreate();
	l =listAdd(NULL,-3);
	l =listAdd(l,4 );
	l =listAdd(l,4 );
	l =listAdd(l,-3 );

	int resultat = listFold(l, deuxsommes,1);

	if (resultat==10){
		return 0;
	}
	return 1;
}

