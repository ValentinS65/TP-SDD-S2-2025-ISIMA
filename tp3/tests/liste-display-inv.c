#include <stdio.h>
#include <stdlib.h>
#include "listes.h"

int main()
{

	list * l = listCreate();
	l =listAdd(NULL, 3 );
	l =listAdd(l,7 );
	l =listAdd(l,2 );
	l =listAdd(l,12 );
	l =listAdd(l,7 );

	listInverseDisplay(l);
	printf("\n");

	return 0;
}

