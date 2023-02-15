
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "dico.h"
#include <string.h>
#define MAX_WORDS 1000 // max words in file

/* ------------------------------------------------------- */

// free memory after using array

void freearray(char **array, int count)
{
  for (int i = 0; i++; i < count)
  {
    free(array[i]);
  }
  free(array);
}

// 1st readmode : file

char **readWordsFile(const char *fileName, int *wordCount)
{
  FILE *file = fopen(fileName, "r");
  if (file == NULL)
  {
    printf("Error opening file.\n");
    return NULL;
  }

  char **words = (char **)malloc(MAX_WORDS * sizeof(char *));
  if (words == NULL)
  {
    printf("Error allocating memory.\n");
    fclose(file);
    return NULL;
  }

  char word[100];
  int i, c, w;
  i = 0;
  w = 0;
  while ((c = fgetc(file)) != EOF)
  {
    if (isalpha(c))
    {
      word[i++] = c;
    }
    else if (i > 0)
    {
      word[i] = '\0';
      words[w] = (char *)malloc((i + 1) * sizeof(char));
      if (words[w] == NULL)
      {
        printf("Error allocating memory.\n");
        fclose(file);
      }
      strcpy(words[w++], word);
      (*wordCount)++;
      i = 0;
    }
  }
  // last word
  if (i > 0)
  {
    word[i] = '\0';
    words[w] = (char *)malloc((i + 1) * sizeof(char));
    if (words[w] == NULL)
    {
      printf("Error allocating memory.\n");
      fclose(file);
    }
    strcpy(words[w++], word);
    (*wordCount)++;
  }

  fclose(file);
  return words;
}

// 2nd readmode : input

char **readWordsInput(int wordCount)
{
  char word[100];
  char **words = (char **)malloc(wordCount * sizeof(char *));
  int i;
  for (i = 0; i < wordCount; i++)
  {
    printf("mot [%d] : ", i);
    scanf("%s", word);
    words[i] = (char *)malloc((strlen(word) + 1) * sizeof(char));
    strcpy(words[i], word);
  }
  return words;
}

// add words of array to tree

void InsererMots(TArbre *dico, char **wordsdico, int wordCount)
{
  for (int i = 0; i < wordCount; i++)
  {
    printf("%s \n", wordsdico[i]);
    dicoInsererMot(wordsdico[i], dico);
  }
}
/* ------------------------------------------------------- */

int main(int argc, char **argv)
{
  int count = 0;
  char input[100];
  TArbre dico;
  char buffer[100];
  char **wordsdico;
  dico = arbreConsVide();

  printf("Choisissez une option :\n[1] Entrer manuellement les mots du dictionnaire.\n[2] Utiliser un fichier pour ajouter les mots.\n");
  scanf("%s", input);

  if (!strcmp(input, "1"))
  {
    printf("Combien de mots souhaitez vous entrer ? \n");
    scanf("%d", &count);
    printf("%d", count);
    wordsdico = readWordsInput(count);
    InsererMots(&dico, wordsdico, count);
    printf("\n Voici l arbre cree \n");
    dicoAfficher(dico);
    printf("\n");
    for (int i = 0; i < count; i++)
    {
      printf("\"%s\" \t -> %d\n", wordsdico[i], dicoNbOcc(wordsdico[i], dico));
    }
  }
  else
  {
    char fileName[100];
    printf("quel est le nom du fichier que vous souhaitez utilisez");
    scanf("%s", &fileName);

    wordsdico = readWordsFile(fileName, &count);
    printf("Read %d words:\n", count);
    InsererMots(&dico, wordsdico, count);
    printf("\n Voici l arbre cree \n");
    dicoAfficher(dico);
    printf("\n");
    for (int i = 0; i < count; i++)
    {
      printf("\"%s\" \t -> %d\n", wordsdico[i], dicoNbOcc(wordsdico[i], dico));
    }
    printf("why the fuck isnt it printing  :\n ");
    print_tree(dico);
  }
  freearray(wordsdico, count);
}

/* ------------------------------------------------------- */
