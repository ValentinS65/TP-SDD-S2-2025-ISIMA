
#include <stdio.h>
#include <stdlib.h>
#include "bTree.h"

extern struct BTreeNode *root;

int main() {
    bTreeInsert(6);
    bTreeInsert(7);
    bTreeInsert(5);
    bTreeInsert(8);
    bTreeInorderTraversal(root);
    bTreeInsert(4);
    bTreeInsert(9);
    bTreeInsert(15);
    bTreeInsert(29);
    bTreeInorderTraversal(root);
}
