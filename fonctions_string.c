#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "devel.h"

void *dupliquer_str(const void *src) {
  /* a completer. Exercice 5, question 1 */
  return (void *)strdup((char *) src); // pour que cela compile
}

void copier_str(const void *src, void *dst) {
  /* a completer. Exercice 5, question 1 */
  strcpy((char *) dst, (char *) src);
}

void detruire_str(void *data) {
  /* a completer. Exercice 5, question 1 */
  free(data);
}

void afficher_str(const void *data) {
  /* a completer. Exercice 5, question 1 */
  printf("%s", (char *) data);
}

int comparer_str(const void *a, const void *b) {
  /* a completer. Exercice 5, question 1 */
  return strcmp((char *) a, (char *) b); // pour que cela compile
}

int ecrire_str(const void *data, FILE *f) {
  /* a completer. Exercice 5, question 1 */
  return fprintf(f, "%s", (char *) data);; // pour que cela compile
}

void *lire_str(FILE *f) {
  /* a completer. Exercice 5, question 1 */
  char *s = malloc(100*sizeof(char));
  int r = fscanf(f,"%s", s);
  if (r < 1) return NULL;
  char *p = strdup(s);
  free(s);
  return p;// pour que cela compile
}
