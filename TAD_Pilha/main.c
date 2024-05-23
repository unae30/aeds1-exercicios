#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include <string.h>

int main()
{
    TPilha Pilha;
    TFila Fila;
    TProduto Produto;
    FPVazia(&Pilha);
    FFVazia(&Fila);

    MENU_PRODUTOS(&Pilha, &Fila);

    LiberarPilha(&Pilha);
    LiberarFila(&Fila);
    return 0;
}
