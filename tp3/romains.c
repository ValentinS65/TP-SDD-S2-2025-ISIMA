#include <stdio.h>
#include <string.h>
#include "romains.h"


int chiffreRomainToDecimal(char chiffreRomain){
	char chiffres[]={'M','D','C','L','X','V','I','f'};
	int valeursDecimales[]={1000,500,100,50,10,5,1};
	for (int i = 0; chiffres[i]!='f';i++){
		if (chiffres[i]==chiffreRomain){
			return valeursDecimales[i];
		}
	}
	return 0;
}


int nombreRomainToDecimal(char* strRomain){
	
	if(strRomain[0]=='\0'){
		return 0;
	}
	else{
		int decimal=chiffreRomainToDecimal(strRomain[0]);

		int next=chiffreRomainToDecimal(strRomain[1]);
		if(next>decimal){
			return nombreRomainToDecimal(strRomain + 2)+(next-decimal);
		}else{
			return nombreRomainToDecimal(strRomain + 1)+decimal;
		}
	}
	
}
