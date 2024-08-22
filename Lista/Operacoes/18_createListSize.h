#ifndef CRIAR_LIST_SIZE_H
#define CRIAR_LIST_SIZE_H

pDLista createListSize(int tam)
{
    /* aloca memoria para o descritor */
    pDLista pd = malloc(sizeof(DLista));

    /* seta os campos com os valores default */
    pd->quantidade = 0;
    pd->primeiro = NULL;
    pd->ultimo = NULL;

    int i;
    for (i = 1; i <= tam; i++)
    {
        addInfoInMiddle(pd, NULL, i);
    }

    return pd;
}

#endif
