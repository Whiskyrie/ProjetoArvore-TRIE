#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>
#include "Utils.h"
#include "Trie.h"

int main()
{

    char alfabeto[] = {'a', 'b', 'c', 'i'};

    pDTrie trie = createTreeTrie(alfabeto, 4);

    char chave1[] = "bacia";
    char chave2[] = "abicia";
    // char chave3[] = "ciba";
    // char chave4[] = "baba";

    /* teste de inclusao */
    addInfoTrie(trie, chave1, strlen(chave1), compareChar, sliceString);
    addInfoTrie(trie, chave2, strlen(chave2), compareChar, sliceString);
    // incluirInfoTRIE(trie, chave3, strlen(chave3), comparaChar, fatiaString);
    // incluirInfoTRIE(trie, chave4, strlen(chave4), comparaChar, fatiaString);

    // removeInfoTrie(trie, chave2, compareChar, sliceString);

    printf("\n\n --- Arvore final --- \n\n");
    printTrie(trie, printChar);
}
