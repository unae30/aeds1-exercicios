#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED


typedef struct{
    int codigo;
    char nome [50];
    char descricao [80];
    float peso;
    float preco;
}TProduto;

typedef struct celula{
    TProduto item;
    struct celula * prox;
}TCelula;

void ImprimirProduto(TProduto Produto);
void LerProduto(TProduto * x);



# endif // UTIL_H_INCLUDED
