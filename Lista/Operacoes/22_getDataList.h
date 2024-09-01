#ifndef GET_DATALIST_H
#define GET_DATALIST_H

void *getListData(DLista *lista, int posicao)
{
    if (lista == NULL || posicao < 0 || posicao >= lista->quantidade)
    {
        return NULL; // Posição inválida ou lista nula
    }

    pNoh atual = lista->primeiro;
    for (int i = 0; i < posicao; i++)
    {
        atual = atual->prox;
    }

    return atual->info; // Assumindo que o nó tem um campo 'info' que armazena o dado
}

#endif // GET_DATALIST_H