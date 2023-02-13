
#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"



/* ------------------------------------------------------- */
/* Primitives de gestion des arbres                        */
/* ------------------------------------------------------- */

TArbre arbreConsVide(void)
{
  return NULL;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int arbreEstVide(TArbre a)
{
  return (a==NULL);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

TArbre arbreCons(char c, int n, TArbre fg, TArbre fd)
{
  TArbre temp;

  temp = (TArbre)malloc(sizeof(struct TNoeud));
  temp->lettre     = c;
  temp->nbocc      = n;
  temp->filsGauche = fg;
  temp->filsDroit  = fd;

  return temp;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

char arbreRacineLettre(TArbre a)
{
  return a->lettre;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int arbreRacineNbOcc(TArbre a)
{
  return a->nbocc;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

TArbre arbreFilsGauche(TArbre a)
{
  return a->filsGauche;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

TArbre arbreFilsDroit(TArbre a)
{
  return a->filsDroit;
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void arbreSuppr(TArbre a)
{
  if (!arbreEstVide(a))
    {
      arbreSuppr(a->filsGauche);
      arbreSuppr(a->filsDroit);
      free(a);
    }
}

/* ------------------------------------------------------- */
