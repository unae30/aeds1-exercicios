#include <stdio.h>
#include <stdlib.h>

#include "interface.h"


void MSG_MENU_PRODUTOS()
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU PRODUTO <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. INSERIR");
    printf("  \n\t2. PESQUISAR");
    printf("  \n\t3. EXCLUIR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t6. SAIR");
}

void MENU_PRODUTOS(TLista *lista1)
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
            printf("\nQuantos produtos voce deseja inserir?");
            scanf("%d", &codAux);

            for(int i=0; i<codAux; i++)
            {
                LerProduto(&produto);
                Inserir(produto,lista1);
            }
            printf("\nProdutos adicionados com sucesso.");
            system("PAUSE");
            break;
        case 2:
            printf("\nQual o codigo do produto que deseja pesquisar?");
            scanf("%d", &codAux);

            produto.codigo = codAux;

            TCelula * pesquisar = Pesquisar(*lista1,produto);

            if(pesquisar!=NULL)
            {
                ImprimirProduto(pesquisar->prox->item);
            }
            else
            {
                printf("\nProduto nao encontrado.\n");
            }
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
            Imprimir(*lista1);
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
