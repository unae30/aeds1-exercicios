#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int codigo;
    char nome [50];
    char descricao [80];
    float peso;
    float preco;
    int prioridade;
}TProduto;

typedef struct celula{
    TProduto item;
    struct celula * prox;
}TCelula;

typedef struct{
    TCelula * frente;
    TCelula * tras;
    int tamanho;
}TFila;

void FFVazia(TFila * Fila);
int FVazia(TFila Fila);
void Enfileirar(TProduto x, TFila * Fila);
void Desenfileirar(TFila * Fila, TProduto * Item);
void ImprimirFIla(TFila * Fila);
TCelula* PesquisarFila(TFila * Fila, int codigo);
void LiberarFila(TFila * Fila);
int mesmosElementos(TFila * Fila1, TFila * Fila2);

void ImprimirProduto(TProduto x);
void LerProduto(TProduto * x);

//missing-------------
//pesquisar
//void LiberarFila(TLista *Lista);


#endif // PRODUTO_H_INCLUDED
