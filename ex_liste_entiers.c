
#include <stdlib.h>
#include "liste.h"
#include "devel.h"
#include "fonctions_entiers.h"

int main(void) {

  /* a completer. Exercice 4, question 1 */

  // Creation d'une liste
  PListe liste = malloc(sizeof(Liste));

  liste->elements = NULL;
  liste->dupliquer = dupliquer_int;
  liste->copier = copier_int;
  liste->detruire = detruire_int;
  liste->afficher = afficher_int;
  liste->comparer =comparer_int;
  liste->ecrire = ecrire_int;
  liste->lire = lire_int;


  // Insertion des elements dans la liste
  void *n4 = malloc(sizeof(int));
  *(int*) n4 = 4;
  void *n3 = malloc(sizeof(int));
  *(int*) n3 = 3;
  void *n2 = malloc(sizeof(int));
  *(int*) n2 = 2;
  void *n6 = malloc(sizeof(int));
  *(int*) n6 = 6;

  void *n7 = malloc(sizeof(int));
  *(int*) n7 = 7;
  afficher_int(n7);
  printf("\n");

  inserer_debut(liste, (n4) );
  inserer_debut(liste, (n3) );
  inserer_debut(liste, (n2) );
  inserer_fin(liste, (n6) );

  printf("Test avec la liste: \n");

  afficher_liste(liste);

  PElement n1 = chercher_liste(liste, n2);
  printf("La recherche de l'entier %d dans la liste: %d\n", *(int *) n2, *((int *) n1->data));

  copier_int(n2, n3);
  printf("Copie de %d : %d\n", *(int *)n2, *(int *)n3);


  printf("Affichage de %d et %d: \n", *((int *) n6), *((int *) n2));
  afficher_int(n6);
  printf(" ");
  afficher_int(n2);
  printf("\n");

  printf("Comparaison de %d et %d : %d\n", *((int *) n6), *((int *) n2), comparer_int(n6, n2));

  printf("Destruction de l'entier %d \n", *((int *) n7));
  detruire_int(n7);

  printf("Destruction de la liste \n");
  detruire_liste(liste);

  FILE *f = fopen("EcrireInt.txt", "w");
  ecrire_int(n4, f);
  fprintf(f, "\n");
  ecrire_int(n3, f);
  fprintf(f, "\n");
  ecrire_int(n2, f);
  fclose(f);

  f = fopen("EcrireInt.txt", "r");
  printf("Le premier nombre lu dans le fichier : %d\n", *(int*)lire_int(f));
  fclose(f);

  detruire_int(n4);
  detruire_int(n3);
  detruire_int(n2);
  detruire_int(n6);

  return 0;
}
