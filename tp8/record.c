#include <stdlib.h>
#include <stdio.h>
#include "record.h"

list * listCreate() {
        list * new=(list*)malloc(sizeof(list));
        new->length=0;
        new->tail=NULL;
        new->head=NULL;
        return new;
}

int listSize(list * l) {
    return l->length;
}

void addRecord(list * l, int variant, int limit) {
    record * new_r=(record*)malloc(sizeof(record));
    new_r->variant=variant;
    new_r->limit=limit;
    if(listSize(l)==0){
        l->head=new_r;
        l->tail=new_r;

    }else{
        l->tail->next=new_r;   
        l->tail=new_r;
    }
    new_r->next=NULL;
    l->length++;

}

void listDisplay(list * l) {
    if (l == NULL) return;
    if(listSize(l)!=0){
        record * tmp=l->head;
        while(tmp!=NULL){
            printf("limit :%d variant:%d \n",tmp->limit,tmp->variant);
            tmp=tmp->next;

        }
        printf("\n");
    }
}

void listFree(list * l){
    if (l == NULL) return;
    if(listSize(l)!=0){
        record * tmp=l->head;
        while(tmp!=NULL){
            record * supr=tmp;
            tmp=tmp->next;
            free(supr);
        }
    }
    l->head=NULL;
    l->tail=NULL;
    l->length=0;
}


void listDestroy(list * l) {
    listFree(l);
    free(l);
}

int veriTer(list * l){
    if(l->head==NULL){
        return 1;
    }
    return abs(l->head->limit-l->head->variant)>=abs(l->tail->limit-l->tail->variant);
}


