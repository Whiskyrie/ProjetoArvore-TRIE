#ifndef ADD_INFO_TRIE_H
#define ADD_INFO_TRIE_H

/* --------------------------*/
pNohTrie addInfoTrieRecursive(pNohTrie raiz, pDLista alfabeto, void *chave, int k, int ordem, int *L, FuncaoComparacao pfc, FuncaoFatiamento pff)
{
   printf("--> Chave = %s - k = %d - L = %d \n ", (char *)chave, k, *L);
   if (*L >= k)
      return raiz;

   // a raiz aponta para o n� que deve receber os pr�ximos k - L s�mbolos da chave
   pNohTrie novo;
   if (*L == k)
   {
      novo = createNohTrie(1, ordem); // novo n� � terminal
   }
   else
   {
      novo = createNohTrie(0, ordem); // novo n� � terminal
   }

   // determina a posi��o j do d�gito da chave (d) dentro do alfabeto
   void *d = pff(chave, *L);
   int characterIndex = containsInfo(alfabeto, d, pfc);
   printf("--> Simbolo = %c - characterIndex = %d \n", *((char *)d), characterIndex);

   // coloca o novo filho no lugar do anterior (que era NULL)
   removeInfoPos(raiz->filhos, characterIndex);
   addInfoInMiddle(raiz->filhos, novo, characterIndex);

   // prepara chamada recursiva
   (*L)++;
   pNohTrie novoFilho = addInfoTrieRecursive(novo, alfabeto, chave, k, ordem, L, pfc, pff);
   return novoFilho;
}

/* ----------------------------------------------------------*/
int addInfoTrie(pDTrie arvore, void *chave, int k, FuncaoComparacaoAlfabeto pfc, FuncaoFatiamento pff)
{

   int L = 0, C = 0;

   // printf("\n Incluindo chave %s", chave);
   pNohTrie noh = searchInfoTrie(arvore, chave, k, &L, &C, pfc, pff);

   printf("Apos a busca da chave %s: L = %d - C = %d \n", (char *)chave, L, C);
   if (C == 1)
   {
      // a chave já está na árvore
      return 0;
   }

   // apás a busca, a variável L representa o último dígito analisado da chave (prefixo)
   addInfoTrieRecursive(noh, arvore->alfabeto, chave, k, arvore->ordem, &L, pfc, pff);
   return 1;
}

#endif
