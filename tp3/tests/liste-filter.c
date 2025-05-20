#include <stdio.h>
#include <stdlib.h>
#include "listes.h"

int estpair(int n){
	return (n%2==0)?1:0;
}



int main()
{

	list * l = listCreate();
	l =listAdd(NULL,152);
	l =listAdd(l,-4 );
	l =listAdd(l,125 );
	l =listAdd(l,-7 );
	l =listAdd(l,-2);
	l =listAdd(l,5 );
	l =listAdd(l,12 );
	l =listAdd(l,5 );
	l =listAdd(l,19 );

	list * l2 = listFilter(l,estpair);

	if ((l2->value==12)&&(l2->next->value==-2)&&(l2->next->next->value==-4&&(l2->next->next->next->value==152)&&l2->next->next->next->next==NULL)){
		return 0;
	}
	else if ((l2->value==152)&&(l2->next->value==-4)&&(l2->next->next->value==-2&&(l2->next->next->next->value==12)&&l2->next->next->next->next==NULL)){
		return 0;
	}
	else{
		return 1;
	}
}

