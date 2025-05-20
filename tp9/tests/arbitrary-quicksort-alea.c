#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(int argc, char ** argv) {
    int test = 1;
    //Creation de liste
    list* l = listCreate();
    l = listAdd(l,2);
    l = listAdd(l,4);
    l = listAdd(l,8);
    l = listAdd(l,5);
    l = listAdd(l,3);
    l = listAdd(l,5);
    l = listAdd(l,7);

    //test
    list* l_copy = quickSort_alea(l);
    if (listSize(l_copy) != 7){
        test = 0;
    }
    if (l_copy->value != 2){
        test = 0;
    }
    if (l_copy->next->value != 3){
        test = 0;
    }
    if (l_copy->next->next->next->value != 5){
        test = 0;
    }
    listFree(l_copy);
    listFree(l);
    return test;
}
