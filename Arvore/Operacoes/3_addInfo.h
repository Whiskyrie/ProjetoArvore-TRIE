#ifndef ADD_INFO_TRIE_H
#define ADD_INFO_TRIE_H

/* --------------------------*/
pNohTrie addInfoTrieRecursive(pNohTrie raiz, pDLista alfabeto, void *chave, int k, int ordem, int *L, FuncaoComparacao pfc, FuncaoFatiamento pff)
{
   if (*L >= k)
   {
      raiz->terminal = 1; // Marca o nó como terminal
      return raiz;
   }

   // determina a posição j do dígito da chave (d) dentro do alfabeto
   void *d = pff(chave, *L);
   int characterIndex = containsInfo(alfabeto, d, pfc);
   free(d); // Libera a memória alocada por pff

   pNohTrie filho = searchInfoPosition(raiz->filhos, characterIndex);

   if (filho == NULL)
   {
      filho = createNohTrie(0, ordem); // Cria um novo nó não-terminal
      removeInfoPos(raiz->filhos, characterIndex);
      addInfoInMiddle(raiz->filhos, filho, characterIndex);
   }

   // prepara chamada recursiva
   (*L)++;
   return addInfoTrieRecursive(filho, alfabeto, chave, k, ordem, L, pfc, pff);
}

int addInfoTrie(pDTrie arvore, void *chave, int k, FuncaoComparacaoAlfabeto pfc, FuncaoFatiamento pff)
{
   int L = 0, C = 0;

   pNohTrie noh = searchInfoTrie(arvore, chave, k, &L, &C, pfc, pff);

   if (C == 1)
   {
      // a chave já está na árvore
      return 0;
   }

   // após a busca, a variável L representa o último dígito analisado da chave (prefixo)
   addInfoTrieRecursive(noh, arvore->alfabeto, chave, k, arvore->ordem, &L, pfc, pff);
   return 1;
}

#endif
