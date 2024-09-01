#ifndef IS_LIST_EMPITY_H
#define IS_LIST_EMPITY_H

int isListEmpity(pDLista lista)
{
    return lista == NULL || lista->quantidade == 0;
}

#endif