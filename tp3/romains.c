#include <stdio.h>
#include <string.h>
#include "romains.h"


int chiffreRomainToDecimal(char chiffreRomain){
	char chiffres[]={'M','D','C','L','X','V','I','f'};
	int valeursDecimales[]={1000,500,100,50,10,5,1};
	int decimal=0;
	for (int i = 0; chiffres[i]!='f';i++){
		if (chiffres[i]==chiffreRomain){
			decimal=valeursDecimales[i];
		}
	}
	return decimal;
}


int nombreRomainToDecimal(char* strRomain){
	
	//printf("Entree dans nombreRomainToDecimal ,  chiffreRomain=%s\n",strRomain);
	int taille=strlen(strRomain);
	int next;
	int decimal=chiffreRomainToDecimal(strRomain[0]);;
	if(taille==1){
		return decimal;
	}
	else{
		next=nombreRomainToDecimal(strRomain + 1);
		if(next>decimal){
			return next-decimal;
		}else{
			return next+decimal;
		}
	}
	//printf("Sortie de nombreRomainToDecimal ,  chiffreRomain=%s , valeur retournee :%d\n",strRomain,decimal);
	
}
