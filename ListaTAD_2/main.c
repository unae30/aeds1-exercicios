#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include <stdbool.h>

int main()
{
    TProduto Produto;
    TLista Lista;
    TLista Lista2;
    TLista Lista3;
    FLVazia(&Lista);
    FLVazia(&Lista2);
    FLVazia(&Lista3);

    Lista.primeiro->item.codigo = 0;
    Lista2.primeiro->item.codigo = 0;



    MENU_PRODUTOS(&Lista, &Lista2);
    Liberar(&Lista);
    Liberar(&Lista2);
    Liberar(&Lista3);

    return 0;
}
