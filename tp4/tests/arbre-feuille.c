#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"

int main(int argc, char ** argv) {
  arbre * a = feuille('a');
  if (a->data == 'a' && a->gauche == NULL && a->droite == NULL) {
    return 0;
  } else {
    return 1;
  }
}
