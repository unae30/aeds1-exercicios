#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include <string.h>

int main()
{
    TPilha Pilha;
    TProduto Produto;
    FPVazia(&Pilha);

    MENU_PRODUTOS(&Pilha);

    LiberarPilha(&Pilha);
    return 0;
}
