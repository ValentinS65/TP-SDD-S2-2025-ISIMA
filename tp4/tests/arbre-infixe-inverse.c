#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"

int main(int argc, char ** argv) {

  arbre * a=noeud('b',
                noeud('h',
                      noeud('a',feuille('c'),feuille('d')),
                      feuille('i')),
                noeud('e',feuille('f'), feuille('g')));

  char buffer[1024];
  FILE* out = fmemopen(buffer, 1024, "w");
  infixe_inverse(out, a);

  fclose(out);
  libere_arbre(&a);

  char* solution = "g\ne\nf\nb\ni\nh\nd\na\nc\n";
  int erreur = strcmp(buffer, solution);
    
  return erreur;
}
