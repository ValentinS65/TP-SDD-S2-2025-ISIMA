#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listes.h"

list * listCreate() {
    return NULL;
}

list * listAdd(list * l,int n){
    list * plist=(list *) malloc(sizeof(list));
    if (plist==NULL) return NULL;

    plist->value=n;
    plist->next=l;
    return plist;
}



void listDisplay(list* l) {
    while (l != NULL) {
        printf("%d -> ", l->value);
        l = l->next;
    }
}


void listInverseDisplay(list * l){
    if(l!=NULL){
        listInverseDisplay(l->next);
        printf("%d->",l->value);
	}
}


int listSearch(list * plist, int n){
    if(plist == NULL) return 0;
    if(plist->value==n) return 1;
    return listSearch(plist->next,n);

}



list * listMap(list* l , int (*f)(int)){
    if(l == NULL) return NULL;
    list * newl=(list*)(malloc(sizeof(list)));
    newl->value=(*f)(l->value);
    newl->next=listMap(l->next,(*f));
    return newl;
   

}

list * listFilter(list* l , int (*p)(int)){
    if (l == NULL) return NULL;
    if((*p)(l->value)==1  ){
        list * newl=(list*)(malloc(sizeof(list)));
        newl->value=l->value;
        newl->next=listFilter(l->next,(*p));
        return newl;
    }
    return listFilter(l->next,(*p));
    
}

int listFold(list* l , int (*op)(int,int),int base){
    if (l == NULL) return base;
    return op(l->value, listFold(l->next, op, base));
}



int add(int a,int b){
    return a+b;
}
int prod(int a,int b){
    return a*b;
}
int count(int a, int b){
    return 1+b;
}
int listSum(list* l ){
    if(l!=NULL){
        return listFold(l,add,0);
    }
    return 0;

}


int listProd(list* l ){
    if(l!=NULL){
        return listFold(l,prod,1);
    }
    return 0;

}

int listLen(list* l ){
    if(l!=NULL){
        return listFold(l,count,0);
    }
    return 0;

}

// concatene à l1 l'inverse de l2
list * ajouteInverse(list * l1,list * l2){
    if(l2!=NULL){
        list * newl=(list*)(malloc(sizeof(list)));
        newl->value=l2->value;
        newl->next=l1;
        return ajouteInverse(newl,l2->next);
    }
    
    return l1;

}

list* listInverse(list *l){
    return ajouteInverse(NULL,l);
    
}



void listFree(list * l){
    list * tmp;
    if(l!=NULL){
        tmp=l;
        listFree(l->next);
        free(tmp);

    }
}