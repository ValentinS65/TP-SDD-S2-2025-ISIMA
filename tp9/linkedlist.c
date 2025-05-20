#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"
#include <time.h>

// Partie donnée aux étudiants
list * listCreate() {
	return NULL;
}

list * listAdd(list * l, int v) {
	list * new = (list *)malloc(1*sizeof(list));
	if (new==NULL) {
		return NULL;
	}
	new->value = v;
	new->next = l;
	return new;
}

int listSize(list * l) {
	int n = 0;
	while (l!=NULL) {
		n = n+1;
		l = l->next;
	}
	return n;
}

void listDisplay(list * l) {
	printf("(");
	while (l) {
		printf("%d", l->value);
		if (l->next) {
			printf(", ");
		}
		l = l->next;
	}
	printf(")\n");
}

list * listRemove(list * l) {
	list * head;
	if (l==NULL) {
		return NULL;
	}
	else {
		head = l->next;
		free(l);
		return head;
	}
}

void listFree(list * l) {
	while (l) {
		l = listRemove(l);
	}
}

list* listInverse(list* l){
    list* l_copy = listCreate();
    while (l){
        l_copy = listAdd(l_copy,l->value);
        l = l->next;
    }
    return l_copy;
}

list* listCopy(list* l){
    list* temp = listInverse(l);
    list* result = listInverse(temp);
    listFree(temp);
    return result;
}

// Exo 1 : quicksort sans mémoire extra
list** listPivot(list* l, int pivot){
    list* gauche = listCreate();
    list* droite = listCreate();
    int pivot_deja_vu=0;
    while(l!=NULL){
        list * tmp=l->next;
        l->next=NULL;
        if(pivot<l->value){
            l->next=droite;
            droite=l;
        }    
        else if(pivot>l->value){
            l->next=gauche;
            gauche=l;
        }else{
            //si on a une valeur egal au pivot presente plus de 1 fois on l'ajoute(le pivot n'est pas ajouté)
            pivot_deja_vu++;
            if(pivot_deja_vu>1){
                l->next=gauche;
                gauche=l;
            }
            else{
                free(l);
            }
        }
        l=tmp;
    }

    list ** duo = (list **) malloc(2*sizeof(list *));
    if (duo){
        duo[0] = gauche;
        duo[1] = droite;
    } else{
        return NULL;
    }
    return duo;
}

list* reassemble(list* gauche, list* droite, int pivot){
    if(gauche!=NULL){
        list * tmp=gauche;
        while(tmp->next!=NULL){
            tmp=tmp->next;
        }
        tmp->next=listAdd(droite,pivot);
        return gauche;}
    else{
        return listAdd(droite,pivot);
    }
}

list* quickSort_rec(list* l){
    if (l == NULL || l->next == NULL) {
        return l;
    }
    int pivot=l->value;
    list**duo=listPivot(l,pivot);
    list * gauche=quickSort_rec(duo[0]);
    list * droite=quickSort_rec(duo[1]);
    free(duo);
    return reassemble(gauche,droite,pivot);
    
}

list* quickSort(list* l){
    list * trie=listCopy(l);
    return quickSort_rec(trie);
}

// Exo 2 : choix du pivot aleatoire
int getRandomElement(list* l){
    srand(time(NULL));
    int taille=0;
    list * tmp=l;
    while(tmp!=NULL){
        taille++;
        tmp=tmp->next;
    }
    int max=rand()%taille;
    tmp=l;
    for(int i=0;i<max;i++){
        tmp=tmp->next;

    }
    
    return tmp->value;
}

int getRandomPivot(list* l){
    int choix1=getRandomElement(l);
    int choix2=getRandomElement(l);
    int choix3=getRandomElement(l);
    if ((choix1 <= choix2 && choix2 <= choix3) || (choix3 <= choix2 && choix2 <= choix1)) {
        return choix2;
    } else if ((choix2 <= choix1 && choix1 <= choix3) || (choix3 <= choix1 && choix1 <= choix2)) {
        return choix1;
    } else {
        return choix3;
    }
}

list* quickSort_rec_alea(list* l){
    if (l == NULL || l->next == NULL) {
        return l;
    }
    int pivot=getRandomPivot(l);
    list**duo=listPivot(l,pivot);
    list * gauche=quickSort_rec(duo[0]);
    list * droite=quickSort_rec(duo[1]);
    free(duo);
    return reassemble(gauche,droite,pivot);   
}

list* quickSort_alea(list* l){
    list * trie=listCopy(l);
    return quickSort_rec_alea(trie);
}
