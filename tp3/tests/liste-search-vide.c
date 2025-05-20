#include <stdio.h>
#include <stdlib.h>
#include "listes.h"

int main()
{

	list * l = listCreate();

	for (int i=-5;i<5;i++)	
		if (listSearch(l , i)==1){
		return 1;
	}
	
	return 0;
	
}

