#include <stdio.h>
#include <stdlib.h>
#include "romains.h"

int main()
{
	char nombreRomain[]="MMMCDIX";
	
	
	int decimal = nombreRomainToDecimal(nombreRomain);

	if (decimal==3409){
		return 0;
	}
	else {
		return 1;
	}
	
	return 0;
}

