#include <stdio.h>
#include <stdlib.h>
#include "listes.h"



int main()
{

	list * l = listCreate();
	l =listAdd(NULL,1);
	l =listAdd(l,2);
	l =listAdd(l,3 );
	l =listAdd(l,4);
	
	list * l2=listInverse(l);

	if ((l2->value==1)&&(l2->next->value==2)&&(l2->next->next->value==3)&&(l2->next->next->next->value==4)&&l2->next->next->next->next==NULL){
		return 0;
	}
	return 1;
}

