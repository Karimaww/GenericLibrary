
#include <stdlib.h>
#include "liste.h"
#include "devel.h"
#include "fonctions_string.h"

int main(void) {

  /* a completer. Exercice 5, question 2 */

  void *s1 = dupliquer_str("s1");
  void *s2 = dupliquer_str("s2");

  printf("Nos chaines de caracteres:\n");
  afficher_str(s1);
  printf("\n");
  afficher_str(s2);
  printf("\n");

  void *s3 = dupliquer_str(s1);
  printf("La duplication de %s : %s\n", (char *) s1, (char *) s3);

  copier_str(s2, s3);
  printf("La copie de %s: %s\n", (char *) s2, (char *) s3);

  if(comparer_str(s1, s2) == 0){
    printf("Les chaines de caracteres %s et %s sont egales\n", (char *) s1, (char *) s2);
  }
  else{
    printf("Les chaines de caracteres %s et %s ne sont pas egales\n", (char *) s1, (char *) s2);
  }

  FILE *f = fopen("EcrireStr.txt", "w");

  ecrire_str(s1, f);
  fprintf(f, "\n");
  ecrire_str(s2, f);
  fprintf(f, "\n");
  ecrire_str(s3, f);
  fprintf(f, "\n");
  fclose(f);


  f = fopen("EcrireStr.txt", "r");
  printf("La premiere chaine de caracteres lu dans le fichier : %s\n", (char *)lire_str(f));
  fclose(f);


  detruire_str(s1);
  detruire_str(s2);
  detruire_str(s3);

  return 0;
}
