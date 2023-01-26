#include <stdio.h>
#include <stdlib.h>
#include "dico.h"
#include <string.h>

void _dicoAfficher(TArbre a, char prefixe[], int pos);
void _dicoInsererMot(char mot[], int debut, TArbre *pa);
int  _dicoNbOcc(char mot[], int debut, TArbre a);

void dicoAfficher(TArbre a)
{
  char buffer[100];

  _dicoAfficher(a, buffer, 0);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void dicoInsererMot(char mot[], TArbre *pa)
{
  _dicoInsererMot(mot, 0, pa);
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int dicoNbOcc(char mot[], TArbre a)
{
  return _dicoNbOcc(mot, 0, a);
}



/* ------------------------------------------------------- */
/* Ent�tes des fonctions locales � cette biblioth�que      */
/* ------------------------------------------------------- */

void _dicoAfficher(TArbre a, char prefixe[], int pos)
{
  if (!arbreEstVide(a))
    {
      prefixe[pos] = arbreRacineLettre(a);

      if (arbreRacineLettre(a) == '\0')
	printf("\"%s\" [%d]\n", prefixe, arbreRacineNbOcc(a));

      _dicoAfficher(arbreFilsGauche(a), prefixe, pos+1);
      _dicoAfficher(arbreFilsDroit(a), prefixe, pos);
    }
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void _dicoInsererMot(char mot[], int debut, TArbre *pa)
{
  if (arbreEstVide(*pa))
    /* 1er cas: le dictionnaire est vide */
    {
      *pa = arbreCons(mot[debut], 0, arbreConsVide(), arbreConsVide());
      if (debut == strlen(mot))
	((*pa)->nbocc)++;
      else
	_dicoInsererMot(mot, debut+1, &((*pa)->filsGauche));
    }
  else if (mot[debut] < arbreRacineLettre(*pa))
    /* 2�me cas: le mot doit �tre plac� au d�but du dictionnaire */
    {
      *pa = arbreCons(mot[debut], 0, arbreConsVide(), *pa);
      if (debut == strlen(mot))
	((*pa)->nbocc)++;
      else
	_dicoInsererMot(mot, debut+1, &((*pa)->filsGauche));
    }
  else if (mot[debut] > arbreRacineLettre(*pa))
    /* 3�me cas: le mot ne commence pas par la m�me lettre que le */
    /* premier mot (courant) du dictionnaire */
    {
      _dicoInsererMot(mot, debut, &((*pa)->filsDroit));
    }
  else
    /* 4�me cas: le mot � ins�rer commence par la m�me lettre que */
    /* le premier mot (courant) du dictionnaire */
    {
      if (debut == strlen(mot))
	((*pa)->nbocc)++;
      else
	_dicoInsererMot(mot, debut+1, &((*pa)->filsGauche));
    }
}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

int _dicoNbOcc(char mot[], int debut, TArbre a)
{
  if (arbreEstVide(a))
    /* 1er cas: le dictionnaire est vide */
    return 0;
  else if (debut > strlen(mot))
    /* 2�me cas: le mot tel quel n'existe pas */
    return 0;
  else if (mot[debut] < arbreRacineLettre(a))
    /* 3�me cas: le mot cherch� aurait d� �tre avant dans le dico */
    return 0;
  else if (mot[debut] == arbreRacineLettre(a))
    /* 4�me cas: le mot commence par la m�me lettre que le premier */
    /* mot du dictionnaire */
    if (mot[debut] == '\0')
      return arbreRacineNbOcc(a);
    else
      return _dicoNbOcc(mot, debut+1, arbreFilsGauche(a));
  else
    /* 5 �me cas: le mot est �ventuellement plus loin dans le dico */
    return _dicoNbOcc(mot, debut, arbreFilsDroit(a));
}

/* ------------------------------------------------------- */