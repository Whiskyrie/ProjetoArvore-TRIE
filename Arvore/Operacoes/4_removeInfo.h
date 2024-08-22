#ifndef REMOVE_INFO_TRIE_H
#define REMOVE_INFO_TRIE_H

static pNohTrie removeInfoTrieRecursive(pNohTrie raiz, pDLista alfabeto, void *chave, int k, int *L, int *C, FuncaoComparacao pfc, FuncaoFatiamento pff)
{
    if (*L >= k)
    {
        return raiz;
    }

    void *d = pff(chave, *L);
    int characterIndex = containsInfo(alfabeto, d, pfc);
    pNohTrie filho = searchInfoPosition(raiz->filhos, characterIndex);

    if (filho == NULL)
    {
        return raiz; // Chave não encontrada
    }

    (*L)++;
    filho = removeInfoTrieRecursive(filho, alfabeto, chave, k, L, C, pfc, pff);

    // Verificar se o nó filho pode ser removido
    if (filho->terminal == 0)
    {
        int hasChildren = 0;
        for (int i = 0; i < getListSize(raiz->filhos); i++)
        {
            if (searchInfoPosition(raiz->filhos, i) != NULL)
            {
                hasChildren = 1;
                break;
            }
        }
        if (!hasChildren)
        {
            // Nó não terminal e sem filhos, pode ser removido
            removeInfoPos(raiz->filhos, characterIndex);
            free(filho);
            return raiz;
        }
    }

    return raiz;
}

int removeInfoTrie(pDTrie arvore, void *chave, int k, FuncaoComparacao pfc, FuncaoFatiamento pff)
{
    int L = 0, C = 0;
    pNohTrie noh = searchInfoTrie(arvore, chave, k, &L, &C, pfc, pff);

    if (noh == NULL || C == 0)
    {
        return 0; // Chave não encontrada
    }

    noh = removeInfoTrieRecursive(arvore->raiz, arvore->alfabeto, chave, k, &L, &C, pfc, pff);
    arvore->raiz = noh;
    return 1;
}

#endif