#include <stdio.h>
#include <stdlib.h>
#include "listes.h"


int moins5(int n){
	return n-5;
}

int main()
{

	list * l = listCreate();
	l =listAdd(NULL,12);
	l =listAdd(l,2 );
	l =listAdd(l,125 );
	l =listAdd(l,-7 );

	list * l2 = listMap(l,moins5);

	if ((l2->value==-12)&&(l2->next->value==120)&&(l2->next->next->value==-3)&&(l2->next->next->next->value==7)&&l2->next->next->next->next==NULL){
		return 0;
	}
	else if ((l2->value==7)&&(l2->next->value==-3)&&(l2->next->next->value==120)&&(l2->next->next->next->value==-12)&&l2->next->next->next->next==NULL){
		return 0;
	}
	else{
		return 1;
	}
	return 0;
}

