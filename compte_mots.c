#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "devel.h"
#include "liste.h"
#include "fonctions_2entiers.h"
#include "fonctions_string.h"

void compte(void *data, void *optarg) {
  /* a completer. Exercice 6, question 2 */

  //La longueur du mot passe en argument
  int len = strlen((char *)data);
  //Cast de l'argument optarg
  PListe liste_double_int = (PListe)optarg;
  //Creation d'une liste temporelle
  PElement tmp = liste_double_int->elements;

  while(tmp){
    //Si la longueur de l'element courant est la meme que du mot passe en argument
    if (((Double_int *)tmp->data)->a == len){
      //Incrementation du compteur
      (((Double_int *)tmp->data)->b)++;
      break;
    }
    tmp = tmp->suivant;
  }
  //Si on a parcouru toute la liste des double_int
  if(!tmp){
    Double_int *d = malloc(sizeof(Double_int));
    d->a = len;
    d->b = 1;
    inserer_place(liste_double_int, d);
  }

}

int main(void) {

  /* a completer. Exercice 6, question 2 */
  //Test avec les fonctions de Double_int
  Double_int *d1 = malloc(sizeof(Double_int));
  d1->a = 15;
  d1->b = 6;

  afficher_2int(d1);
  printf("\n");

  Double_int *d2 = dupliquer_2int(d1);
  afficher_2int(d1);
  printf("\n");

  Double_int *d3 = malloc(sizeof(Double_int));
  copier_2int(d1, d3);
  afficher_2int(d3);
  printf("\n");

  printf("La Comparaison des Double_int ");
  afficher_2int(d1);
  printf(" et ");
  afficher_2int(d2);
  printf(": %d\n", comparer_2int(d1, d2));

  FILE *f = fopen("Ecrire2Int.txt", "w");
  ecrire_2int(d1, f);
  fprintf(f, "\n");
  ecrire_2int(d2, f);
  fprintf(f, "\n");
  ecrire_2int(d3, f);
  fclose(f);

  f = fopen("Ecrire2Int.txt", "r");
  printf("Le premier Double_int lu dans le fichier: ");
  afficher_2int(lire_2int(f));
  printf("\n");
  fclose(f);

  detruire_2int(d1);
  detruire_2int(d2);
  detruire_2int(d3);
  /*

  //Creation d'une liste du dictionnaire francais
  PListe dico = malloc(sizeof(PListe));

  dico->elements = NULL;
  dico->dupliquer = dupliquer_str;
  dico->copier = copier_str;
  dico->detruire = detruire_str;
  dico->afficher = afficher_str;
  dico->comparer =comparer_str;
  dico->ecrire = ecrire_str;
  dico->lire = lire_str;

  //Lecture des mots francais
  lire_liste(dico, "test");

  //Creation d'une liste des elements de type Double_int
  PListe liste_double_int = malloc(sizeof(PListe));

  liste_double_int->elements = NULL;
  liste_double_int->dupliquer = dupliquer_2int;
  liste_double_int->copier = copier_2int;
  liste_double_int->detruire = detruire_2int;
  liste_double_int->afficher = afficher_2int;
  liste_double_int->comparer =comparer_2int;
  liste_double_int->ecrire = ecrire_2int;
  liste_double_int->lire = lire_2int;

  //Creation du pointeur vers la fonction compte
  void (*compte_ptr)(void *, void *);
  compte_ptr = &compte;

  map(dico, compte_ptr, liste_double_int);
  afficher_liste(liste_double_int);

  detruire_liste(dico);
  detruire_liste(liste_double_int);
  */

  return 0;
}
