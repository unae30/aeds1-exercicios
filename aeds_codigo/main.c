#include <stdio.h>
#include <stdlib.h>
#include "produto.h"
#include <string.h>

int main()
{
    TLista listah;
    FLVazia(&listah);
    TProduto produto;
    int cod=0;

    int menu;
    do
    {
        printf("\nMENU:");
        printf("\n 1- Adicionar produto na lista");
        printf("\n 2- Pesquisar produto na lista");
        printf("\n 3- Excluir produtos com o codigo impar da lista");
        printf("\n 4- Sair do menu");
        printf("\nDigite a opcao desejada:");
        scanf("%d", &menu);
        switch(menu)
        {

        case 1:
            printf("\nQuantos produtos voce deseja adicionar?");
            int qntd;
            scanf("%d", &qntd);


            for(int i=0; i<qntd; i++)
            {
                LerProduto(&produto);
                Inserir(produto, &listah);
            }
            printf("\nProdutos adicionados com sucesso.");
            Imprimir(listah);

            break;
        case 2:
            printf("\nQual o codigo do produto que deseja pesquisar?");
            scanf("%d", &cod);

            TProduto produtoAuxiliar;
            produtoAuxiliar.codigo = cod;

            TCelula * pesquisar = Pesquisar(listah, produtoAuxiliar);

            if(pesquisar!=NULL)
            {
                ImprimirProduto(pesquisar->prox->item);
            }
            else
            {
                printf("\nProduto nao encontrado.\n");
            }
            break;
        case 3:
            printf("\nExcluindo produtos de codigo impar...");
            TCelula * Auxiliar1;
            Auxiliar1 = listah.primeiro;
            while(Auxiliar1 != NULL)
            {
                if(Auxiliar1->prox->item.codigo % 2 != 0)
                {
                    Excluir(&listah, &Auxiliar1->prox->item);
                }
                Auxiliar1 = Auxiliar1->prox;
            }
            printf("\nConcluido!\n");
            break;
        case 4:
            printf("\nPrograma finalizado.");
            return 0;

        default:
            printf("Digite uma opcao valida.");

        }
    }
    while(menu);

    Liberar(&listah);

    return 0;
}
