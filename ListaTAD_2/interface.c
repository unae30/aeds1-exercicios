#include <stdio.h>
#include <stdlib.h>

#include "interface.h"
#include <stdbool.h>


void MSG_MENU_PRODUTOS()
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU LISTA <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. COMPARAR LISTAS");
    printf("  \n\t2. CONCATENAR LISTAS");
    printf("  \n\t3. DIVIDIR LISTA");
    printf("  \n\t4. IMPRIMIR I-ESIMA CELULA");
    printf("  \n\t5. EXCLUIR I-ESIMA CELULA");
    printf("  \n\t6. SAIR");
}

void MENU_PRODUTOS(TLista *lista1, TLista * lista2)
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
            if(comparaListas(*lista1, *lista2))
            {
                printf("\nIGUAIS.\n");
            }
            else
            {
                printf("\nDIFERENTES.\n");
            }

            system("PAUSE");
            break;
        case 2:
            printf("\nConcatenando lista 1 e lista 2\n");
            concatenarListas(lista1, lista2);
            system("PAUSE");
            break;
        case 3:
            printf("\nDigite o codigo do produto que voce deseja excluir...");
            scanf("%d", &codAux);
            TCelula * Auxiliar1 = Pesquisar(*lista1, produto);
            if(Auxiliar1!=NULL)
            {
                produto = Auxiliar1->prox->item;
                printf("\nProduto a excluir:\n");
                ImprimirProduto(produto);
                Excluir(lista1,&produto);
            }
            else
            {
                printf("\nO produto nao foi excluido pois nao foi encontrado.");
            }
            system("PAUSE");
            break;
        case 4:
            printf("\nDigite o i-esimo termo a ser impresso da lista 1:");
            scanf("%d", &codAux);
            imprimirIesimo(*lista1, codAux);
            system("PAUSE");
            break;
        case 5:
            printf("\nDigite o i-esimo termo a ser excluido da lista 1:");
            scanf("%d", &codAux);
            excluirEnesimo(lista1, codAux);
            system("PAUSE");
            break;
        case 6:
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

