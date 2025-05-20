#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"

int main() {
    /*
    stack * p=stackCreate();
    printf("vide ? :%d\n",stackIsEmpty(p));
    stackDisplay(p);
    stackFree(p);
    p=stackAdd(p,5);
    p=stackAdd(p,10);
    stackDisplay(p);
     printf("vide ? :%d\n",stackIsEmpty(p));
     for(int i=0;i<8;i++){
        p=stackAdd(p,i);
     }
     stackDisplay(p);
      stackFree(p);
      free(p);
      */
    queue * q=queueCreate();
    printf("vide ? :%d\n",queueIsEmpty(q));
    queueDisplay(q);
    queueDestroy(q);
    queue * q1=queueCreate();
    queueAdd(q1,5);
    queueAdd(q1,10);
    queueDisplay(q1);
        queueDestroy(q1);

    queue * q2=queueCreate();
    queueAdd(q2,5);
    queueAdd(q2,10);
    queueAdd(q2,7);
    queueRemove(q2);
    queueDisplay(q2);
        queueDestroy(q2);

    queue * q3=queueCreate();
    queueAdd(q3,5);
    queueRemove(q3);
    queueDisplay(q3);
    queueDestroy(q3);
    
    queue * q4=queueCreate();

    for(int i=0;i<100;i++){
        queueAdd(q4,i);

    }for(int i=0;i<100;i++){
    queueRemove(q4);

    }
    queueDisplay(q4);
    queueDestroy(q4);
    

    return 0;
}
