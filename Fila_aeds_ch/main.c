#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

int main()
{
    TProduto produto;
    TFila Fila;
    FFVazia(&Fila);

    MENU_PRODUTOS(&Fila);
    LiberarFila(&Fila);
    return 0;
}
