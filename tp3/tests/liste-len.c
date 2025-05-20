#include <stdio.h>
#include <stdlib.h>
#include "listes.h"



int main()
{

	list * l = listCreate();
	int l0=listLen(l);
	l =listAdd(NULL,-3);
	l =listAdd(l,4 );
	l =listAdd(l,4 );
	l =listAdd(l,-3 );
	
	int l1=listLen(l);
	if (l0==0&&l1==4){
		return 0;
	}
	return 1;
}

