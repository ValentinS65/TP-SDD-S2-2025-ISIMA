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
encodage * inverse_encodage(encodage * e) {
  encodage * res = NULL;
  while (e != NULL) {
    res = cree_encodage(e->data, res);
    e = e->suivant;
  }
  return res;
}
int code_char(arbre * a, char c, encodage ** e) {
    if (est_feuille(a)) {
    return a->data == c;
  }

  encodage * tmp = NULL;

  if (code_char(a->gauche, c, &tmp)) {
    tmp = cree_encodage(0, tmp);
  } else if (code_char(a->droite, c, &tmp)) {
    tmp = cree_encodage(1, tmp);
  } else {
    return 0;
  }

  // Inverse temporaire pour remettre dans le bon sens
  encodage * tmp_inv = inverse_encodage(tmp);
  libere_encodage(&tmp);

  // Ajoute à la fin de e
  encodage * cur = tmp_inv;
  while (cur != NULL) {
    *e = cree_encodage(cur->data, *e);
    cur = cur->suivant;
  }

  libere_encodage(&tmp_inv);
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
   if (a == NULL || e == NULL) return NULL;

  if (est_feuille(a)) {
    fprintf(f, "%c", a->data);
    return e;
  }

  if (e->data == 0) {
    return decode_suivant(f, a->gauche, e->suivant);
  } else {
    return decode_suivant(f, a->droite, e->suivant);
  }
}

void decode(FILE * f, arbre * a, encodage * e) {
  encodage * p=e;
  while(p!=NULL){
    p=decode_suivant(f,a,p);
  }
}

