#ifndef PRINT_TRIE_H
#define PRINT_TRIE_H
#define ESPACO 5

void printTrieRecursive(pNohTrie raiz, pDLista alfabeto, FuncaoImpressao fi)
{

  if (raiz == NULL)
  {
    printf(" * - ");
    return;
  }

  if (raiz->filhos == NULL ||
      raiz->filhos->quantidade == 0)
  {
    printf("[ * ]");
    return;
  }

  int i;
  printf("[ ");
  for (i = 0; i < raiz->filhos->quantidade; i++)
  {
    void *iEsimoFilho = searchInfoPosition(raiz->filhos, i + 1);
    if (iEsimoFilho != NULL)
      fi(searchInfoPosition(alfabeto, i + 1));

    printTrieRecursive(iEsimoFilho, alfabeto, fi);
  }

  printf(" ]");
}

void printTrie(pDTrie arvore, FuncaoImpressao fi)
{

  printTrieRecursive(arvore->raiz, arvore->alfabeto, fi);
}

#endif
