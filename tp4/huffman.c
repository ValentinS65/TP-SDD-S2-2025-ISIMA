#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"
#include "huffman.h"

arbrepoids * cree_arbrepoids(arbre * a, int poids) {
  arbrepoids * ap =  malloc(sizeof(struct arbrepoids));
  if (ap != NULL) {
    ap->element = a;
    ap->poids = poids;
  }
  return ap;
}

liste * cree_liste(arbre * a, int poids, liste * suivant) {
  liste * res = malloc(sizeof(struct liste));

  if (res != NULL) {
    arbrepoids * ap = cree_arbrepoids(a, poids);
    if (ap != NULL) {
      res->data = ap;
    }
    res->suivant = suivant;
  }

  return res;
}
liste * genere_liste(char * s) {
  int t[256];
  int i;
  for(i=0;i<256;i++){
    t[i]=0;
  }
  i=0;
  while(s[i]!='\0'){
    t[(int)s[i]]++;
    i++;
  }
  liste * res=NULL;
  for(i=0;i<256;i++){
    if(t[i]!=0){
      res=cree_liste(feuille(i),t[i],res);
    }
  }
  
  return res;
}
arbrepoids * extrait_min(liste ** l) {
  if (*l == NULL) return NULL;

  liste * temp = *l;
  liste * min_prev = NULL;
  liste * min_node = temp;
  liste * prev = NULL;

  int min = temp->data->poids;

  while (temp != NULL) {
    if (temp->data->poids < min) {
      min = temp->data->poids;
      min_prev = prev;
      min_node = temp;
    }
    prev = temp;
    temp = temp->suivant;
  }

  if (min_prev == NULL) {
    *l = min_node->suivant;
  } else {
    min_prev->suivant = min_node->suivant;
  }

  arbrepoids * res = min_node->data;
  free(min_node);
  return res;
}


arbre * huffman(char * s) {
  liste * l=genere_liste(s);
  arbre * A;
  arbrepoids * min1;
  arbrepoids * min2;
  while(l->suivant!=NULL){
    min1=extrait_min(&l);
    min2=extrait_min(&l);
    A=noeud('*',min1->element,min2->element);
    l=cree_liste(A,min1->poids+min2->poids,l);
    free(min1);
    free(min2);
  }
  if (l != NULL) {
    A = l->data->element;
    free(l->data);
    free(l);
}
  return A;
}
