#ifndef PRINT_TRIE_H
#define PRINT_TRIE_H
#define MAX_DEPTH 100

void printTrieRecursive(pNohTrie raiz, pDLista alfabeto, FuncaoImpressao fi, int depth, char *prefix)
{
  if (raiz == NULL)
    return;

  printf("%s", prefix);

  if (raiz->filhos == NULL || raiz->filhos->quantidade == 0)
  {
    printf("*\n");
    return;
  }

  printf("\n");

  char newPrefix[1024];
  for (int i = 0; i < raiz->filhos->quantidade; i++)
  {
    void *iEsimoFilho = searchInfoPosition(raiz->filhos, i + 1);
    if (iEsimoFilho != NULL)
    {
      void *simbolo = searchInfoPosition(alfabeto, i + 1);

      strcpy(newPrefix, prefix);
      if (i == raiz->filhos->quantidade - 1)
      {
        strcat(newPrefix, "    ");
      }
      else
      {
        strcat(newPrefix, "|   ");
      }

      printf("%s+-- ", prefix);
      fi(simbolo);
      printf("\n");

      printTrieRecursive(iEsimoFilho, alfabeto, fi, depth + 1, newPrefix);
    }
  }
}

void printTrie(pDTrie arvore, FuncaoImpressao fi)
{
  printf("Trie Structure:\n");
  char prefix[1024] = "";
  printTrieRecursive(arvore->raiz, arvore->alfabeto, fi, 0, prefix);
}

#endif