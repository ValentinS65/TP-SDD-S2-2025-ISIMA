#include <stdio.h>
#include <stdlib.h>
#include "listes.h"

int main()
{

	list * l = listCreate();	

	listInverseDisplay(l);
	printf("\n");

	return 0;
}

