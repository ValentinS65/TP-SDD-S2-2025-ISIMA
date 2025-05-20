#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

stack * stackCreate() {
	stack * new=NULL;
	return new;
}

int stackIsEmpty(stack * s) {
	if(s==NULL){
		return 1;
	}
	return 0;
}

stack * stackAdd(stack * s, int v) {
	stack * tete=(stack*)(malloc(sizeof(stack)));
	tete->value=v;
	tete->next=s;
	return tete;
}

int stackTop(stack * s) {
	if(stackIsEmpty(s)){
		return -1;
	}
	return s->value;
}

stack * stackRemove(stack * s) {
	if(stackIsEmpty(s)){
		return NULL;
	}
	stack * tete=s;
	s=s->next;
	free(tete);
	return s;
}

int stackSize(stack * s) {
	if(stackIsEmpty(s)){
		return -1;
	}	
	int n=1;
	stack * tmp=s;
	while(tmp->next!=NULL){
		n++;
		tmp=tmp->next;
	}
	return n;
}

void stackDisplay(stack * s) {
	printf("Display :\n");
	if(!stackIsEmpty(s)){
	stack * tmp=s;
	
	while(tmp->next!=NULL){
		printf("%d\n",tmp->value);
		tmp=tmp->next;
	}
	printf("%d\n",tmp->value);
	}
}

void stackFree(stack * s) {
if(!stackIsEmpty(s)){
	stack * tmp;
	while(s->next!=NULL){
		tmp=s;
		s=s->next;
		free(tmp);
	}
}}
