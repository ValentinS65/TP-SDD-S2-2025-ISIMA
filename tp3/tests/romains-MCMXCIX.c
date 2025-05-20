#include <stdio.h>
#include <stdlib.h>
#include "romains.h"

int main()
{
	char nombreRomain[]="MCMXCIX";
	
	
	int decimal = nombreRomainToDecimal(nombreRomain);

	if (decimal==1999){
		return 0;
	}
	else {
		return 1;
	}
	
	return 0;
}

