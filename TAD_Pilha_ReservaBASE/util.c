#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ImprimirProduto(TProduto x)
{
    printf("\n Codigo: %d", x.codigo);
    printf("\n Nome: %s", x.nome);
    printf(" Descricao: %s", x.descricao);
    printf(" Peso: %.2f", x.peso);
    printf("\n Preco: %.2f", x.preco);
}

void LerProduto(TProduto * x)
{
    printf("\nDigite o id do produto:");
    fflush(stdin);
    scanf("%d", &x->codigo);
    printf("\nDigite o nome do produto:");
    fflush(stdin);
    fgets(x->nome, 50, stdin);
    printf("\nDigite o descricao do produto:");
    fflush(stdin);
    fgets(x->descricao, 50, stdin);
    printf("\nDigite o peso do produto:");
    fflush(stdin);
    scanf("%f", &x->peso);
    printf("\nDigite o preco do produto:");
    fflush(stdin);
    scanf("%f", &x->preco);

}
