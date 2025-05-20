#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(int argc, char ** argv) {
    int test = 1;
    list* l = listCreate();
    l = listAdd(l,2);
    if (listSize(l) != 1){
        test = 0;
    }
    int pivot = 3;
    list** duo = listPivot(l,pivot);
    if (!duo){
        test = 0;
    }
    if (listSize(duo[0]) != 1 || duo[0]->value != 2){
        test = 0;
    }
    if (listSize(duo[1]) != 0){
        test = 0;
    }
    listFree(duo[0]);
    free(duo);
    return test;
}
