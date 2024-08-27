#ifndef REMOVE_LIST_INFO_H
#define REMOVE_LIST_INFO_H

int removeListInfo(pDLista lista, pNoh noRemover)
{
    if (lista == NULL || noRemover == NULL)
    {
        return 0; // Falha: lista ou nó inválido
    }

    // Se for o primeiro nó
    if (lista->primeiro == noRemover)
    {
        lista->primeiro = noRemover->prox;
        if (lista->primeiro != NULL)
        {
            lista->primeiro->ant = NULL;
        }
    }
    else
    {
        // Conecta o nó anterior ao próximo
        noRemover->ant->prox = noRemover->prox;
    }

    // Se for o último nó
    if (lista->ultimo == noRemover)
    {
        lista->ultimo = noRemover->ant;
        if (lista->ultimo != NULL)
        {
            lista->ultimo->prox = NULL;
        }
    }
    else
    {
        // Conecta o próximo nó ao anterior
        noRemover->prox->ant = noRemover->ant;
    }

    // Libera a memória do nó removido
    free(noRemover->info);
    free(noRemover);

    // Decrementa a quantidade de elementos na lista
    lista->quantidade--;

    return 1; // Sucesso
}

#endif
