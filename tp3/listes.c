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
    if(plist->value==n){
        return 1;
    }
    else{
        if(plist->next!=NULL){
            listSearch(plist->next,n);
        }}
     return 0;
}



list * listMap(list* l , int (*f)(int)){
    list * newl=(list*)(malloc(sizeof(list)));
    newl->value=(*f)(l->value);
    if(l->next!=NULL){
        newl->next=listMap(l->next,(*f));
    }else{
        newl->next=NULL;
    }
    return newl;
   

}

list * listFilter(list* l , int (*p)(int)){
    if((*p)(l->value)==1 && l!=NULL){
        list * newl=(list*)(malloc(sizeof(list)));
        newl->value=l->value;
        if(l->next!=NULL){
            newl->next=listFilter(l->next,(*p));
        }else{
            newl->next=NULL;
        }
        return newl;
    }
    if(l->next!=NULL){
        return listFilter(l->next,(*p));
    }
    return NULL;

}

int listFold(list* l , int (*op)(int,int),int base){

   if(l!= NULL && l->next!=NULL){
        return (*op)(l->value,listFold(l->next,(*op),base));
   }
   else{
        return (*op)(l->value,base);
   }
}


int add(int a,int b){
    return a+b;
}
int prod(int a,int b){
    return a*b;
}
int count(int a, int b){
    return b+1;
}
int listSum(list* l ){
    int res=0;
    if(l!=NULL){
        res+=listFold(l,add,0);
    }
      return res;
}


int listProd(list* l ){
    int res=0;
    if(l!=NULL){
        res+=listFold(l,prod,1);
    }
      return res;      
}

int listLen(list* l ){
      int res=0;
    if(l!=NULL){
        res+=listFold(l,count,0);
    }
      return res;     
}

// concatene à l1 l'inverse de l2
list * ajouteInverse(list * l1,list * l2){
    list * newl=(list*)(malloc(sizeof(list)));
    if(l2!=NULL){
        newl->value=l2->value;
        newl->next=l1;
    }
    if(l2->next!=NULL){
        return ajouteInverse(newl,l2->next);
        

    }
    return newl;

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