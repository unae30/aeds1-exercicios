#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include <string.h>

void MSG_MENU_PRODUTOS()
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU PILHA <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. EMPILHAR");
    printf("  \n\t2. DESEMPILHAR");
    printf("  \n\t3. IMPRIMIR");
    printf("  \n\t4. PESQUISAR");
    printf("  \n\t5. Inverter parte (k)");
    printf("  \n\t6. SAIR");
}

void MENU_PRODUTOS(TPilha * Pilha)
{
    TProduto x;
    TFila Fila;
    int opcao=0;
    int k;
    do
    {
        MSG_MENU_PRODUTOS();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            LerProduto(&x);
            Empilha(x,Pilha);
            system("PAUSE");
            break;
        case 2:
            Desempilha(Pilha,&x);
            system("PAUSE");
            break;
        case 3:
            ImprimirPilha(Pilha);
            system("PAUSE");
            break;
        case 4:
            printf("Digite o nome do produto que deseja pesquisar:\n");
            fflush(stdin);
            fgets(x.nome, 50, stdin);
            int pesquisa = PesquisarPilha(Pilha,&x);
            if(pesquisa == 1){
                ImprimirProduto(x);
            }else{
                printf("Produto nao encontrado.\n");
            }
            system("PAUSE");
            break;
        case 5:
            printf("Informe o valor k\n");
            fflush(stdin);
            scanf("%d", &k);
            InverteParte(k,Pilha);
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
    }while(opcao != 6);
}

