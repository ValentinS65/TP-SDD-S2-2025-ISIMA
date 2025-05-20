#include <stdio.h>
#include <stdlib.h>
#include "base.h"


int main()
{

	setBase(7);

	list * l2=decToBase(541);


	// printf ("%d %d %d %d",(l2->value==2),(l2->next->value==0),(l2->next->next->value==4),(l2->next->next->next->value==1));

	if ((l2->value==2)&&(l2->next->value==0)&&(l2->next->next->value==4)&&(l2->next->next->next->value==1)&&l2->next->next->next->next==NULL){

		return 0;
	}
	else{
		return 1;
	}

}

