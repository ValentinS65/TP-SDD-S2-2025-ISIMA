#include <stdio.h>
#include <stdlib.h>
#include "listes.h"

int main()
{

	list * l = listCreate();
	l =listAdd(NULL, 3 );
	l =listAdd(l,12 );
	l =listAdd(l,2 );
	l =listAdd(l,12 );
	l =listAdd(l,-7 );

	
	if (listSearch(l , 3)==1 &&listSearch(l , 12)==1 &&listSearch(l , -7)==1 &&listSearch(l , 1)==0){
		return 0;
	}
	else{
		return 1;
	} 

	return 0;
}

