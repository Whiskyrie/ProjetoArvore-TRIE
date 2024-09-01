#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Utils.h"
#include "Trie.h"

void testSearch(pDTrie trie, char *chave)
{
    int L = 0, C = 0;
    size_t chave_len = strlen(chave);
    pNohTrie result = searchInfoTrie(trie, (void *)chave, (int)chave_len, &L, &C, compareChar, sliceString);
    if (C == 1)
    {
        printf("A chave '%s' foi encontrada na Trie.\n", chave);
    }
    else if (result != NULL)
    {
        printf("A chave '%s' nao foi encontrada na Trie. ", chave);
        if ((size_t)L == chave_len)
        {
            printf("Prefixo encontrado, mas nao e uma chave completa.\n");
        }
        else
        {
            printf("Busca parou no nivel %d.\n", L);
        }
    }
    else
    {
        printf("A chave '%s' nao foi encontrada na Trie. Busca parou no nivel %d.\n", chave, L);
    }
}
int main()
{
    // Define o alfabeto para a TRIE
    char alfabeto[] = {'a', 'b', 'c', 'i', 's'};
    pDTrie trie = createTreeTrie(alfabeto, sizeof(alfabeto) / sizeof(alfabeto[0]));

    // Define as chaves a serem adicionadas
    char *chave1 = "bacia";
    char *chave2 = "abicia";
    char *chave3 = "casa";

    /* Teste de inclusão */
    addInfoTrie(trie, (void *)chave1, (int)strlen(chave1), compareChar, sliceString);
    addInfoTrie(trie, (void *)chave2, (int)strlen(chave2), compareChar, sliceString);
    addInfoTrie(trie, (void *)chave3, (int)strlen(chave3), compareChar, sliceString);

    printf("\n\n --- Árvore final --- \n\n");
    printTrie(trie, printChar);

    printf("\n\n --- Testes de busca --- \n\n");
    testSearch(trie, "bacia");
    testSearch(trie, "abicia");
    testSearch(trie, "b");
    testSearch(trie, "bac");
    testSearch(trie, "casa");

    return 0;
}