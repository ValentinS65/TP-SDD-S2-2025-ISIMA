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
  if (*l == NULL) {
      return NULL; // Handle empty list
  }

  int min = (*l)->data->poids;
  arbrepoids * a_min = (*l)->data;
  liste * temp = *l;
  liste * prev = NULL;

  // Find the minimum element
  while (temp != NULL) {
      if (min > temp->data->poids) {
          min = temp->data->poids;
          a_min = temp->data;
      }
      temp = temp->suivant;
  }

  // Remove the minimum element
  temp = *l;
  if (temp->data == a_min) {
      *l = temp->suivant;
      free(temp);
  } else {
      while (temp != NULL && temp->data != a_min) {
          prev = temp;
          temp = temp->suivant;
      }
      if (temp != NULL) {
          prev->suivant = temp->suivant;
          free(temp);
      }
  }

  return a_min;
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
