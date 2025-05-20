#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "avl.h"

void testAbr();
void testAvl();

int main(void) {
	testAbr();
	testAvl();
	return 0;
}

void testAbr() {
		int i;	
//test 1
	struct bst * abr;
    abr = NULL;
    bstDisplay(abr);
    printf("\n");
    abr=bstInsert(abr,6);
    abr=bstInsert(abr,7);
    abr=bstInsert(abr,5);
    abr=bstInsert(abr,8);
    abr=bstInsert(abr,4);
    abr=bstInsert(abr,9);
    abr=bstInsert(abr,1);
    abr=bstInsert(abr,3);
    bstDisplay(abr);
	printf("\n");

    bstInorderTraversal(abr);
    abr=bstDelete(abr,7);
    bstDisplay(abr);
	printf("\n");
	bstDisplay(bstMinValue(abr->left));
	printf("\n");
	    bstFree(abr);






	// test number 2
	abr = NULL;
	printf("Ajout de 100 entiers (dans le désordre) :\n");
	for (i=0; i<100; i++) {
		abr = bstInsert(abr, (123*i+456)%100);
	}
	bstInorderTraversal(abr);
	bstFree(abr);
	// test number 3
	abr = NULL;
	printf("Ajout de 10 entiers (dans le désordre) :\n");
	for (i=0; i<10; i++) {
		abr = bstInsert(abr, (123*i+456)%100);
	}
	bstInorderTraversal(abr);
	bstDisplay(abr);
    printf("\n");
	bstFree(abr);
	
}

void testAvl() {
	int i;
	struct avl * avl;
	// test number 1
	avl = NULL;
	for (i=0; i<10; i++) {
		avl = avlInsert(avl, i);
	}
	printf("Ajout de 10 entiers :\n");
	avlDisplay(avl);
	avlFree(avl);
	
	// test number 2
	avl = NULL;
	for (i=0; i<10; i++) {
		avl = avlInsert(avl, i);
	}
	printf("Ajout de 10 entiers, et suppression de 1 et 0 :\n");
	avl = avlDelete(avl, 1);
	avl = avlDelete(avl, 0);
	avlDisplay(avl);
    printf("\n");
	avlFree(avl);
	
}
