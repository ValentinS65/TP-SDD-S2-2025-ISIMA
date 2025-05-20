#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(void) {
    struct avl * avl;
    avl = NULL;
    avlDisplay(avl);
    printf("\n");
    avlFree(avl);
	return 0;
}
