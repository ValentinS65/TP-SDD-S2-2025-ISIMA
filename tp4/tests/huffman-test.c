#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"
#include "huffman.h"

int main(int argc, char ** argv) {
  char* s = "ababaaacad";

  arbre * a = huffman(s);
  int erreur = 0;

  erreur = erreur || ((a->gauche)->data != 'a' && (a->droite)->data != 'a');

  if (a->droite->data == 'a')
    a = a->gauche;
  else
    a = a->droite;

  erreur = erreur || (a->gauche->data != 'b' && a->droite->data != 'b');

  if (a->droite->data == 'b')
    a = a->gauche;
  else
    a = a->droite;

  erreur = erreur || (a->gauche->data != 'd' && a->droite->data != 'd')
    || (a->gauche->data != 'c' && a->droite->data != 'c');

  return erreur;
}
