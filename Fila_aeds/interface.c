#include <stdio.h>
#include <stdlib.h>

#include "interface.h"
#include <stdbool.h>


void MSG_MENU_PRODUTOS()
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU LISTA <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. ENFILEIRAR");
    printf("  \n\t2. DESENFILEIRAR");
    printf("  \n\t3. IMPRIMIR");
    printf("  \n\t4. PESQUISAR");
    printf("  \n\t5. SAIR");
}

void MENU_PRODUTOS(TFila * Fila)
{
    TProduto produto;
    int opcao=0;
    int codAux;
    do
    {
        MSG_MENU_PRODUTOS();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            LerProduto(&produto);
            Enfileirar(produto, Fila);
            system("PAUSE");
            break;
        case 2:
            Desenfileirar(Fila,&produto);
            system("PAUSE");
            break;
        case 3:
            ImprimirFIla(Fila);
            system("PAUSE");
            break;
        case 4:
            printf("Digite o codigo do produto que deseja fazer a pesquisa:\n");
            fflush(stdin);
            scanf("%d", &codAux);
            PesquisarFila(Fila, codAux);
            system("PAUSE");
            break;
        case 5:
            system("cls");
            printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
            system("PAUSE");
            break;
        default:
            system("cls");
            printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
            system("PAUSE");
        } // fim do bloco switch
    }
    while(opcao != 5);
}

