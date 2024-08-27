#ifndef GET_LIST_SIZE_H
#define GET_LIST_SIZE_H

int getListSize(pDLista lista)
{
    if (lista == NULL)
    {
        return 0;
    }
    return lista->quantidade;
}
#endif