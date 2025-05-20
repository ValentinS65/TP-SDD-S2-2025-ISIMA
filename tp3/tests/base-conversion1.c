#include <stdio.h>
#include <stdlib.h>
#include "base.h"


int main()
{

	list * l = listCreate();
	l =listAdd(NULL,1);
	l =listAdd(l,3);
	l =listAdd(l,7 );
	l =listAdd(l,2 );

	setBase(7);

	int decimal=baseToDec(l);

	if (decimal==541){
		return 0;
	}
	else{
		return 1;
	}

}

