#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(void) {
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
    bstInorderTraversal(abr);
    abr=bstDelete(abr,7);
    bstDisplay(abr);
    bstDisplay(bstMinValue(abr->left));



    bstFree(abr);
	return 0;
}
