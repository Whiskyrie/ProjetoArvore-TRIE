#ifndef SEARCH_INFO_TRIE_H
#define SEARCH_INFO_TRIE_H

/* ----------------------------------------------------------*/
pNohTrie searchInfoTrieRecursive(pNohTrie raiz, pDLista alfabeto, void *chave, int k, int *L, int *C, FuncaoComparacao pfc, FuncaoFatiamento pff)
{
    if (*L == k)
    {
        *C = raiz->terminal;
        return raiz;
    }

    void *d = pff(chave, *L);
    int characterIndex = containsInfo(alfabeto, d, pfc);
    free(d);

    if (characterIndex == 0)
    {
        return raiz;
    }

    pNohTrie filho = searchInfoPosition(raiz->filhos, characterIndex);
    if (filho == NULL)
    {
        return raiz;
    }

    (*L)++;
    return searchInfoTrieRecursive(filho, alfabeto, chave, k, L, C, pfc, pff);
}

pNohTrie searchInfoTrie(pDTrie arvore, void *chave, int k, int *L, int *C, FuncaoComparacao pfc, FuncaoFatiamento pff)
{
    *L = 0;
    *C = 0;
    return searchInfoTrieRecursive(arvore->raiz, arvore->alfabeto, chave, k, L, C, pfc, pff);
}

#endif
