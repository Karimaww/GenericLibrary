#include <stdlib.h>
#include <stdio.h>
#include "devel.h"

#include "fonctions_2entiers.h"

void *dupliquer_2int(const void *src) {
  /* a completer. Exercice 6, question 1 */
  Double_int *dst = malloc(sizeof(Double_int));
  if (dst==NULL) {
    affiche_message("Erreur d'allocation");
    return NULL;
  }
  Double_int *isrc = (Double_int *)src;
  dst->a = isrc->a;
  dst->b = isrc->b;
  return (void *)dst; // pour que cela compile
}

void copier_2int(const void *src, void *dst) {
  /* a completer. Exercice 6, question 1 */
  Double_int *idst = (Double_int *)dst;
  Double_int *isrc = (Double_int *)src;
  *idst = *isrc;

}

void detruire_2int(void *data) {
  /* a completer. Exercice 6, question 1 */
  free(data);
}

void afficher_2int(const void *data) {
  /* a completer. Exercice 6, question 1 */
  printf("%d %d", ((Double_int *)data)->a, ((Double_int *)data)->b);
}

int comparer_2int(const void *a, const void *b) {
  /* a completer. Exercice 6, question 1 */
  int ia = ((Double_int *)a)->a;
  int ib = ((Double_int *)b)->a;

  return (ia>ib)-(ia<ib); // pour que cela compile
}

int ecrire_2int(const void *data, FILE *f) {
  /* a completer. Exercice 6, question 1 */
  return fprintf(f, "%d %d", ((Double_int *)data)->a, ((Double_int *)data)->b); // pour que cela compile
}

void *lire_2int(FILE *f) {
  /* a completer. Exercice 6, question 1 */
  Double_int *data = malloc(sizeof(Double_int));
  fscanf(f, "%d %d", &((Double_int *)data)->a, &((Double_int *)data)->b);
  return (void *)data; // pour que cela compile
}
