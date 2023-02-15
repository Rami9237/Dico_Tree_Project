/* ------------------------------------------------------- */
/* Projet Info GTR1 2001-2002 (MM)                         */
/* fichier "dico.h"                                        */
/* ------------------------------------------------------- */

#include "arbre.h"



/* ------------------------------------------------------- */
/* Primitives de gestion d'un dictionnaire                 */
/* ------------------------------------------------------- */

void dicoAfficher(TArbre a);
void dicoInsererMot(char mot[], TArbre *pa);
int  dicoNbOcc(char mot[], TArbre a);
void print_tree(TArbre a);

/* ------------------------------------------------------- */
