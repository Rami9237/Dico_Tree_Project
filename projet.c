/* ------------------------------------------------------- */
/* Projet Info GTR1 2001-2002 (MM)                         */
/* fichier "projet.c"                                      */
/* ------------------------------------------------------- */
#include <stdlib.h>
#include <stdio.h>
#include "dico.h"
#include <string.h>

/* ------------------------------------------------------- */

int main(int argc, char **argv)
{ 
  int nbdico;
  char input[100];
  TArbre dico;
  char buffer[100];
  char **wordsdico; 
  dico = arbreConsVide();
  
    printf("Choisissez une option :\n[1] Entrer manuellement les mots du dictionnaire.\n[2] Utiliser un fichier pour ajouter les mots.\n");
    scanf("%s",input);

  if (!strcmp(input,"1"))
  {
    printf("Combien de mots souhaitez vous entrer ? \n");
    scanf("%d",&nbdico);
    printf("%d",nbdico);
    wordsdico = (char**)malloc(nbdico * sizeof(char*));
    int i;
    for (i=0;i<nbdico;i++)
    {
      printf("mot [%d] : ",i);
      scanf("%s",buffer);
      dicoInsererMot(buffer,&dico);
      wordsdico[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
      strcpy(wordsdico[i], buffer); 
    }
    printf("\n Voici l arbre cree \n");
    dicoAfficher(dico);
    printf("\n");  
    for (int i=0;i<nbdico;i++)
    {
    printf("\"%s\" \t -> %d\n", wordsdico[i], dicoNbOcc(wordsdico[i], dico));
    }
  }
  else {
    printf("quel est le nom du fichier que vous souhaitez utilisez");
  }
 
}

/* ------------------------------------------------------- */
