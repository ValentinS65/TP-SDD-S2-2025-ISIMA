#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"
#include <string.h>
list * listCreate() {
	list * newList=NULL;
	return newList;
}

hashtable * hashtableCreate(int n) {
	hashtable * newHash=(hashtable*)(malloc(sizeof(hashtable)));
	newHash->n=n;
	newHash->tab=(list**)(malloc(sizeof(list*)*n));
	for(int i=0;i<n;i++){
		newHash->tab[i]=(list*)malloc(sizeof(list));
	}
	return newHash;
}

int hash(char * key, int n) {
	int sum=0;
	while(*key!='\0'){
		sum+=*key;
		key++;
	}
	return sum%n;
}

void listDisplay(list * l) {
	list * tmp=l;
	if(tmp->next!=NULL){
		printf("{");
		while(tmp->next!=NULL){
			printf("key : %s  value : %s\n",tmp->key,tmp->value);
			tmp=tmp->next;
		}
		printf("}\n");
	}

}

void hashtableDisplay(hashtable * h) {
	for(int i=0;i<h->n;i++){
		listDisplay(h->tab[i]);

	}
}

list * listAdd(list * l, char * newK, char * newV) {
	list * newl=(list*)malloc(sizeof(list));
	newl->key=newK;
	newl->value=newV;
	newl->next=l;
	return newl;
}

char * listSearch(list * l, char * k) {
	list * tmp=l;
	while(tmp->next!=NULL){
		if(strcmp(tmp->key,k)==0){
			return tmp->value;
		}
		tmp=tmp->next;
	}
	return NULL;
}

char * hashtableSearch(hashtable * h, char * key) {
	int code = hash(key, h->n);
	return listSearch(h->tab[code], key);
}

void hashtableAdd(hashtable * h, char * key, char * value) {
	int code=hash(key,h->n);
	if(h->tab[code] == NULL || listSearch(h->tab[code],key)==NULL){
		h->tab[code]=listAdd(h->tab[code],key,value);
	}
}

void listFree(list * l) {
	list * tmp;
	while(l->next!=NULL){
			tmp=l;
			l=l->next;
			free(tmp);
	}
	free(l);
}
void hashtableFree(hashtable * h) {
	for(int i=0;i<h->n;i++){
		listFree(h->tab[i]);
	}
	free(h->tab);
	free(h);
}

hashtable * hashtableRehash(hashtable * h, int newN) {
	hashtable * newH=hashtableCreate(newN);
	list * tmp;
	for(int i=0;i<h->n;i++){
		tmp=h->tab[i];
		while(tmp->next!=NULL){
			hashtableAdd(newH,tmp->key,tmp->value);
			tmp=tmp->next;
		}
	}
	free(h);
	return newH;
}
