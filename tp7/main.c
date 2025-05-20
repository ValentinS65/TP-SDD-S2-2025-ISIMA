#include <stdio.h>
#include <stdlib.h>
#include "bTree.h"

int main() {
    struct BTreeNode * root = NULL;
    root = bTreeInsert(root, 8);
    root = bTreeInsert(root, 9);
    root = bTreeInsert(root, 10);
    root = bTreeInsert(root, 11);
    root = bTreeInsert(root, 15);
    root = bTreeInsert(root, 16);
    root = bTreeInsert(root, 17);
    root = bTreeInsert(root, 18);
    root = bTreeInsert(root, 20);
    root = bTreeInsert(root, 23);

    bTreeInorderTraversal(root);

    root = bTreeDelete (root, 20);
    printf("\n");
    bTreeInorderTraversal(root);
}
