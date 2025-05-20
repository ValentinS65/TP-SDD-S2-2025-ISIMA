#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arbre.h"

arbre * feuille(char c){
  arbre * new=(arbre*)malloc(sizeof(arbre));
  new->data=c;
  new->droite=NULL;
  new->gauche=NULL;
  return new;
}

arbre * noeud(char c, arbre * g, arbre * d){
  arbre * new=(arbre*)malloc(sizeof(arbre));
  new->data=c;
  new->droite=d;
  new->gauche=g;
  return new;}

int est_feuille(arbre * a) {
  if(a->gauche==NULL && a->droite==NULL){
    return 1;
  }
  return 0;
}

void libere_arbre(arbre ** a){
  if(*a!=NULL){
    libere_arbre(&((*a)->gauche));
    libere_arbre(&((*a)->droite));
    free(*a);
    *a=NULL;}

  
}

void infixe_inverse(FILE * f, arbre * a) {
  if(a!=NULL){
    infixe_inverse(f,a->gauche);
    fprintf(f,"%c\n",a->data);
    infixe_inverse(f,a->droite);

  }
}

void imprime_blancs(FILE * f, int niveau, int est_droit) {
  for(int i=0;i<niveau*3;i++){
    fprintf(f," ");
  }
  if(est_droit){
    fprintf(f,"/-");
  }
  else{
    fprintf(f,"\\-");
  }
}

void imprime_avec_blancs(FILE * f, arbre * a, int niveau, int est_droit) {
  if(a!=NULL){
    imprime_avec_blancs(f,a->droite,niveau+1,1);
    imprime_blancs(f,niveau,est_droit);
    fprintf(f,"%c\n",a->data);
    imprime_avec_blancs(f,a->gauche,niveau+1,0);
  }
}

void imprime_arbre(FILE * f, arbre * a){
  imprime_avec_blancs(f,a->droite,1,1);
  fprintf(f,"%c\n",a->data);
  imprime_avec_blancs(f,a->gauche,1,0);
}


