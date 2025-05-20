#include <stdlib.h>
#include <stdio.h>
#include "codage.h"

encodage * cree_encodage(binaire data, encodage * suivant) {
  encodage * res = malloc(sizeof(struct listeBinaire));
  if (res != NULL) {
    res->data = data;
    res->suivant = suivant;
  }
  
  return res;
}

void imprime_encodage(FILE * f, encodage * e) {
  encodage * reste = e;
  while(reste != NULL) {
    fprintf(f, "%i", reste->data);
    reste = reste->suivant;
  }
  fprintf(f, "\n");
}


void libere_encodage(encodage ** e) {
  if (*e != NULL) {
    libere_encodage(&(*e)->suivant);
    free(*e);
    *e = NULL;
  }
}

int code_char(arbre * a, char c, encodage ** e) {
    if(est_feuille(a)){
      return a->data==c;
    }
    if(code_char(a->droite,c,e)){
      *e=cree_encodage(0,*e);
      
    }
    else if(code_char(a->gauche,c,e)){
      *e=cree_encodage(1,*e);
    }
    else{
      return 0;
    }
    return 1;

  
}

encodage * code_texte(arbre * a, char * s) {
  int i=0;
  encodage * res=NULL;
  while(s[i]!='\0'){
    code_char(a,s[i],&res);
    i++;
  }
  return res;
}

encodage * decode_suivant(FILE * f, arbre * a, encodage * e) {
  encodage * parcours=e;
  if(a->data!='*'){
    fprintf(f,"%c",a->data);
    return parcours;
  }
  if(e->data==0){
    decode_suivant(f,a->droite,e->suivant);
  }
  else{
    decode_suivant(f,a->gauche,e->suivant);

  }
}

void decode(FILE * f, arbre * a, encodage * e) {
  encodage * p=e;
  while(p!=NULL){
    p=decode_suivant(f,a,p);
  }
}

