#ifndef CREATE_TREE_TRIE_H
#define CREATE_TREE_TRIE_H

//---------------------------------
pNohTrie createNohTrie(int terminal, int ordem)
{

    pNohTrie pNovo = malloc(sizeof(NohTrie));
    pNovo->filhos = createListSize(ordem);
    pNovo->terminal = terminal;
    return pNovo;
}

/* --------------------------*/
pDTrie createTreeTrie(char alfabeto[], int ordem)
{
    pDTrie trie = malloc(sizeof(DTrie));
    trie->raiz = createNohTrie(0, ordem); // o zero indica que a raiz não é terminal
    trie->ordem = ordem;
    trie->alfabeto = createList();

    // fazer um loop para adicionar cada elemento do alfabeto[] na lista do alfabeto
    // do descritor
    int i;
    for (i = 0; i < ordem; i++)
    {
        char *simbolo = malloc(sizeof(char));
        *simbolo = alfabeto[i];
        addInfoInMiddle(trie->alfabeto, simbolo, i + 1);
    }

    return trie;
};

#endif
