#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

queue * queueCreate() {
	queue * q=(queue*)(malloc(sizeof(queue)));
	q->size=0;
	q->head=NULL;
	q->tail=NULL;
	return q;
}

int queueIsEmpty(queue * q) {
	if(q->size==0){
		return 1;
	}
	return 0;
}

void queueAdd(queue * q, int v) {
	queue_element * new=(queue_element*)(malloc(sizeof(queue_element)));
	   new->value = v;
    new->previous = NULL; 

    if (q->head == NULL) { 
        new->next = NULL;
        q->tail = new; 
    } else {
        new->next = q->head; 
        q->head->previous = new; 
    }

    q->head = new; 
    q->size++;



}

int queueGet(queue * q) {
	if(!queueIsEmpty(q)){
		return q->tail->value;}
	return -1;
}

void queueRemove(queue * q) {
	if(!queueIsEmpty(q)){
		queue_element * tmp=q->tail;
		q->tail=q->tail->previous;
		if (q->tail) { 
			q->tail->next = NULL;
        } else { 
            q->head = NULL;
        }
		free(tmp);
		q->size--;
	}
}

void queueDestroy(queue * q) {
	if(!queueIsEmpty(q)){
		while(q->tail->previous!=NULL){
			queueRemove(q);
		}
	}
	free(q);
}

int queueSize(queue * q) {
	return q->size;
}

void queueDisplay(queue * q) {
	printf("Display :\n");

	if(!queueIsEmpty(q)){

		queue_element * tmp;
		tmp=q->tail;
		while(tmp!=NULL){
			printf("%d\n",tmp->value);
			tmp=tmp->previous;
		}
	}
}
