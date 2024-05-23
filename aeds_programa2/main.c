#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

int main()
{
    TProduto Produto;
    TLista Lista;


    MENU_PRODUTOS(&Lista);
    Liberar(&Lista);


    return 0;
}
