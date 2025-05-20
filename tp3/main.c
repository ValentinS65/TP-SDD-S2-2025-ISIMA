#include <stdio.h>
#include <string.h>
#include "romains.h"
#include "listes.h"
#include "base.h"
#include "dames.h"
#include "sierpinski_SDL.h"


///////////////////////////////////////////////////////////////////////////
//
//  Ce fichier contient permet aux étudiants de tester toutes les fonctions du TP 3
//
//  Les tests sont faits dans des fonctions (certaines sont à compléter).
//
//  L'appel à ces fonctions peut être commenté/décommenté à volonté dans le main
//
///////////////////////////////////////////////////////////////////////////


//------------------------------------------------------------------
// tests question 1 : Première fonction récursive (nombres romains )
//------------------------------------------------------------------

int test_romains()
{
	char nombreRomain[200];
	printf("Entrez un nombre romain : ");
	scanf("%s",nombreRomain);

	printf("resultat juste : %d\n",nombreRomainToDecimal(nombreRomain));

	return 0;
}

//------------------------------------------------------------------
// tests question 2 : Récursivité et listes
//------------------------------------------------------------------

list * liste_de_test(){
	list * l = listCreate();
	l =listAdd(NULL, 2 );
	l =listAdd(l,5 );
	l =listAdd(l,1 );
	l =listAdd(l,4 );
	l =listAdd(l,2 );

return l;
}

void test_listDisplay(){

	list * l=liste_de_test();
	printf("Affichage de la liste : ");
	listDisplay(l);
	printf("\n");

	listFree(l);
}

void test_listInverseDisplay(){

	list * l=liste_de_test();
	printf("Affichage inverse de la liste : ");
	listInverseDisplay(l);
	printf("\n");

	listFree(l);
}

void test_listSearch()
{

	list * l=liste_de_test();
	int n=4;
	printf("Recherche de %d dans la liste : %d\n",n,listSearch(l , n));
	n=2;
	printf("Recherche de %d dans la liste : %d\n",n,listSearch(l , n));
	n=3;
	printf("Recherche de %d dans la liste : %d\n",n,listSearch(l , n));
	n=7;
	printf("Recherche de %d dans la liste : %d\n",n,listSearch(l , n));

	listFree(l);

}

// TO DO : question 5
// Ecrire ici la fonction carre
int carre(int n){
	return n*n;
}
void test_listMap(){

	list * l =liste_de_test();
	printf("Liste des carres : ");

	listDisplay(listMap(l,carre));

	printf("\n");
	listFree(l);

}

// TO DO : question 6
// Ecrire ici la fonction sup3
int sup3(int n){
	if(n>3){
		return 1;
	}
	return 0;
}
void test_listFilter(){
	list * l =liste_de_test();
	printf("Liste filtree : ");

	listDisplay(listFilter(l,sup3));
	
	printf("\n");
	listFree(l);

}

void test_listSum(){
	list * l =liste_de_test();
	int resultat = listSum(l);
	printf("Somme : %d\n",resultat);
	listFree(l);
}

void test_listProd(){
	list * l =liste_de_test();
	int resultat = listProd(l);
	printf("Produit : %d\n",resultat);
	listFree(l);
}
void test_listLen(){
	list * l =liste_de_test();
	int resultat = listLen(l);
	printf("Longueur : %d\n",resultat);
	listFree(l);
}
void test_listInverse(){
	list * l =liste_de_test();
	list * l2 =listInverse(l);
	printf("Inverse de la liste ");
	listDisplay(l2);
	printf("\n");

	listFree(l);
	listFree(l2);
	
}

//------------------------------------------------------------------
// tests question 3 : Changement de base
//------------------------------------------------------------------

list* liste2_de_test(){
	list * l =listCreate();
	l =listAdd(l, 1 );
	l =listAdd(l, 10 );
	l =listAdd(l, 15 );
	l =listAdd(l,5 );
	return l;

}

void test_printBaseB(){
	setBase(16);
	list * l=liste2_de_test();
	printf("Affichage d'un nombre en base 16 : ");
	printBaseB(l);
	printf("\n");
	listFree(l);
}

void test_baseToDec(){
	setBase(16);
	list * l=liste2_de_test();
	printf("Conversion en décimal : %d\n",baseToDec(l));

	listFree(l);
}
void test_baseToDec2(){
	setBase(16);
	list * l=liste2_de_test();
	printf("Conversion en décimal méthode 2 : %d\n",baseToDec2(l));

	listFree(l);
}
void test_decToBase(){
	setBase(16);
	list * l=decToBase(6901);
	printf("Conversion en base b : ");
	printBaseB(l);
	printf("\n");

	listFree(l);
}

void test_global(int n,int b)
{
	setBase(b);
	
	list * l = decToBase(n);
	printf("Nombre initial , %d\n",n);
	printf("Nombre en base %d : ",b);
	printBaseB(l);
	printf("\n");
	printf("Nombre retransformé en décimal %d \n",baseToDec(l));

	listFree(l);

}

//------------------------------------------------------------------
// tests question 4 : Problème des 8 dames
//------------------------------------------------------------------
 
int test_dames(){
	
	liste_solutions * solutions=NULL;
	int n=8;
	int * placement =(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		placement[i]=-1;
	}
	solutions=addAllSolutions(NULL,placement,0,n);
	free(placement); 
	// Affichage du nombre de solutions et des solutions
	printf("Nombre  de solutions : %d\n",nbSolutions(solutions));
	
	printf("Ensemble des solutions :\n");
	displaySolutions(solutions,n);
	freeSolutions(solutions);
	return 0;

}

int main()
{
    //------------------------------------------------------------------
    // tests question 1 : Première fonction récursive (nombres romains )
    //------------------------------------------------------------------
    //test_romains();


    //------------------------------------------------------------------
    // tests question 2 : Récursivité et listes
    //------------------------------------------------------------------
	/*
    test_listDisplay();
	
	test_listInverseDisplay();
	
	test_listSearch();

	test_listMap();

	test_listFilter();
	test_listSum();
	test_listProd();
	test_listLen();


	test_listInverse();

    //------------------------------------------------------------------
    // tests question 3 : Changement de base
    //------------------------------------------------------------------
	
    test_printBaseB();
	
	test_baseToDec();
	
	//test_baseToDec2();
	test_decToBase();
	
	test_global(55,2);
	test_global(55,8);
	test_global(55,16);
    

	setBase(2);
	test_baseToDec();
	setBase(16);
	test_baseToDec();

//------------------------------------------------------------------
// tests question 4 : Problème des 8 dames
//------------------------------------------------------------------

    
    test_dames();
    
	*/
//------------------------------------------------------------------
// tests question 5 : Fractales triangles de Sierpinski
//------------------------------------------------------------------

    /*
    main_SDL();
    */   
}


