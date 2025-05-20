#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "codage.h"
#include "huffman.h"


// fonction qui permet de lire un fichier
// en temps qu'une chaine de caractères
char * lecture_fichier(char* nom) {
  FILE * f = fopen(nom, "rb");
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  fseek(f, 0, SEEK_SET);

  char *string = malloc(fsize + 1);
  fread(string, fsize, 1, f);
  fclose(f);

  string[fsize] = 0;
  return string;
}

void test_impression() {

  // chargement du fichier solution
  char* solution = lecture_fichier("impression.txt");
  arbre * a=noeud('b',
                feuille('a'),
                noeud('d',
                      feuille('c'),
                      noeud('f', feuille('e'), feuille('g'))));
  char buffer[1024];
  FILE* out = fmemopen(buffer, 1024, "w");
  imprime_arbre(out, a);
  fclose(out);

  int test = !strcmp(buffer, solution);
    printf("%s",buffer);

  libere_arbre(&a);
  free(solution);
  
  if(test) {
    printf("impression : ok\n");
  } else {
    printf("impression : erreur\n");
  }
}
void test_huffman(){

  arbre * res=huffman("barbapapa");
  imprime_arbre(stdout,res);
  libere_arbre(&res);


}

int main() {
  //test_impression();
  //test_huffman();
  
  char * s="barbapapa";
  arbre * a=huffman(s);
  encodage * e=code_texte(a,s);
  imprime_encodage(stdout,e);
  decode(stdout,a,e);
  libere_encodage(&e);
  libere_arbre(&a);
}
