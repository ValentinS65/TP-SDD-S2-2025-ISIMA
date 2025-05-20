#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "codage.h"
#include "huffman.h"

int main(int argc, char ** argv) {
      arbre * a=noeud('*',
                noeud('*',
                      noeud('*',feuille('c'),feuille('d')),
                      feuille('a')),
                noeud('*',feuille('f'), feuille('g')));

      int erreur = 0;

      char buffer[1024];
      FILE* file;
      encodage * enc;

      enc = NULL;
      code_char(a, 'a', enc);
      file = fmemopen(buffer, 1024, "w");
      imprime_encodage(file, enc);
      fclose(file);
      erreur = erreur || strcmp(buffer, "01\n") != 0;

      libere_encodage(enc);
      code_char(a, 'c', enc);
      file = fmemopen(buffer, 1024, "w");
      imprime_encodage(file, enc);
      fclose(file);
      erreur = erreur || strcmp(buffer, "000\n") != 0;

      libere_encodage(enc);
      code_char(a, 'd', enc);
      file = fmemopen(buffer, 1024, "w");
      imprime_encodage(file, enc);
      fclose(file);
      erreur = erreur || strcmp(buffer, "001\n") != 0;

      libere_encodage(enc);
      code_char(a, 'f', enc);
      file = fmemopen(buffer, 1024, "w");
      imprime_encodage(file, enc);
      fclose(file);
      erreur = erreur || strcmp(buffer, "10\n") != 0;

      libere_encodage(enc);
      code_char(a, 'g', enc);
      file = fmemopen(buffer, 1024, "w");
      imprime_encodage(file, enc);
      fclose(file);
      erreur = erreur || strcmp(buffer, "11\n") != 0;

      libere_arbre(&a);
      libere_encodage(&enc);
      return erreur;
}
