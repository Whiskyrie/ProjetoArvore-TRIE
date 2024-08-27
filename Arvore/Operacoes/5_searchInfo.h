#ifndef SEARCH_INFO_TRIE_H
#define SEARCH_INFO_TRIE_H

/* ----------------------------------------------------------*/
pNohTrie searchInfoTrieRecursive(pNohTrie raiz, pDLista alfabeto, void *chave, int k, int *L, int *C, FuncaoComparacao pfc, FuncaoFatiamento pff)
{

    if (*L < k)
    {
        // determina a posi��o j do d�gito da chave (d) dentro do alfabeto
        void *d = pff(chave, *L);
        int characterIndex = containsInfo(alfabeto, d, pfc);
        pNohTrie filho = searchInfoPosition(raiz->filhos, characterIndex);
        if (filho != NULL)
        {
            (*L)++;
            return searchInfoTrieRecursive(filho, alfabeto, chave, k, L, C, pfc, pff);
        }
        return raiz;
    }
    else
    {
        if (raiz->terminal == 1)
        {
            *C = 1; // indica que a chave foi localizada na �rvore
            return raiz;
        }
        // Se o L >= k e o nó não é terminal, significa que a chave não foi encontrada
        return NULL;
    }
}
/* ----------------------------------------------------------*/
pNohTrie searchInfoTrie(pDTrie arvore, void *chave, int k, int *L, int *C, FuncaoComparacao pfc, FuncaoFatiamento pff)
{
    *L = 0;
    *C = 0;
    return searchInfoTrieRecursive(arvore->raiz, arvore->alfabeto, chave, k, L, C, pfc, pff);
}

#endif
