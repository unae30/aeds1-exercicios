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
}TProduto;

typedef struct celula{
    TProduto item;
    struct celula * prox;
}TCelula;

typedef struct{
    TCelula * primeiro;
    TCelula * ultimo;
    int tamanho;
}TLista;

void FLVazia(TLista * Lista);
int Vazia(TLista Lista);
void Inserir(TProduto x, TLista * Lista);
void ImprimirProduto(TProduto x);
void Imprimir(TLista Lista);
TCelula * Pesquisar(TLista Lista, TProduto Item);
void Excluir (TLista * Lista, TProduto * Item);
void LerProduto(TProduto * x);
void Liberar(TLista *Lista);

//1
bool comparaListas(TLista Lista1, TLista Lista2);
//2
void concatenarListas(TLista* lista1, TLista* lista2);
//3
void dividirLista(TLista *listaPrincipal, TLista *lista1, TLista *lista2);
//4
void imprimirIesimo(TLista Lista, int numero);
//5
void excluirEnesimo(TLista *Lista, int numero);


#endif // PRODUTO_H_INCLUDED
