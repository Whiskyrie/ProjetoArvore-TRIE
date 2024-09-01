#ifndef REMOVE_INFO_TRIE_H
#define REMOVE_INFO_TRIE_H

int removeInfoTrieRecursive(pNohTrie no, pDLista alfabeto, void *chave, int k, int *L, FuncaoComparacao pfc, FuncaoFatiamento pff)
{
    if (*L == k)
    {
        if (no->terminal)
        {
            no->terminal = 0; // Remove a marcação de terminal
            return 1;         // Chave removida com sucesso
        }
        return 0; // Chave não encontrada
    }

    void *d = pff(chave, *L);
    int characterIndex = containsInfo(alfabeto, d, pfc);
    free(d);

    if (characterIndex == 0)
    {
        return 0; // Caractere não encontrado no alfabeto
    }

    pNohTrie filho = searchInfoPosition(no->filhos, characterIndex);
    if (filho == NULL)
    {
        return 0; // Caminho não existe, chave não encontrada
    }

    (*L)++;
    int removed = removeInfoTrieRecursive(filho, alfabeto, chave, k, L, pfc, pff);

    // Se o filho não é mais necessário, removê-lo
    if (removed && !filho->terminal && isListEmpity(filho->filhos))
    {
        removeInfoPos(no->filhos, characterIndex);
        free(filho->filhos);
        free(filho);
    }

    return removed;
}

int removeInfoTrie(pDTrie arvore, void *chave, int k, FuncaoComparacao pfc, FuncaoFatiamento pff)
{
    int L = 0;
    return removeInfoTrieRecursive(arvore->raiz, arvore->alfabeto, chave, k, &L, pfc, pff);
}

#endif