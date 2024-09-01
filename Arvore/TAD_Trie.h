#ifndef Trie_TAD_H
#define Trie_TAD_H
/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/

/* estrutura do noh da arvore B */
typedef struct nohTrie NohTrie;
typedef NohTrie *pNohTrie;

/* descritor da arvore B */
typedef struct dTrie DTrie;
typedef DTrie *pDTrie;

/* tipos referentes aos ponteiros para funcao */
typedef int (*FuncaoComparacaoAlfabeto)(void *, void *);
typedef void (*FuncaoImpressao)(void *);
typedef void *(*FuncaoFatiamento)(void *, int);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDTrie createTreeTrie(char alfabeto[], int ordem); // alfabeto e seu tamanho

int addInfoTrie(pDTrie arvore, void *chave, int k, FuncaoComparacaoAlfabeto pfc, FuncaoFatiamento pff);

int removeInfoTrie(pDTrie arvore, void *chave, int k, FuncaoComparacao pfc, FuncaoFatiamento pff);

pNohTrie searchInfoTrie(pDTrie arvore, void *chave, int k, int *L, int *C, FuncaoComparacao pfc, FuncaoFatiamento pff);

void desenhaTrie(pDTrie, FuncaoImpressao);

#endif
