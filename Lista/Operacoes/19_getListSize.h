int getListSize(pDLista lista)
{
    if (lista == NULL)
    {
        return 0;
    }
    return lista->quantidade;
}