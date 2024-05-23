#include "fila.h"
#include "produto.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "util.h"

/*Fila*/

void FFVazia(TFila * Fila)
{
    Fila->frente= (TCelula*) malloc(sizeof (TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}

int FVazia(TFila Fila)
{
    return (Fila.frente == Fila.tras);
}

void Enfileirar(TProduto x, TFila * Fila)
{
    Fila->tras->prox = (TCelula*) malloc(sizeof (TCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item=x;
    Fila->tras->prox = NULL;
    Fila->tamanho++;
}

void Desenfileirar(TFila * Fila, TProduto * Item)
{
    TCelula * aux;
    if(!FVazia(*Fila)){
        aux = Fila->frente->prox;
        Fila->frente->prox= aux->prox;
        *Item = aux->item;
        free(aux);
        if(Fila->frente->prox == NULL){
            Fila->tras = Fila->frente;
        }
        Fila->tamanho--;
    }
}

void ImprimirFIla(TFila * Fila)
{
    TProduto produto;
    int n = Fila->tamanho;
    for(int i=0; i<n; i++){
        Desenfileirar(Fila, &produto);
        ImprimirProduto(produto);
        Enfileirar(produto, Fila);
    }
}

void LiberarFila(TFila * Fila)
{
    TProduto produto;
    int n = Fila->tamanho;
    for(int i=0; i<n; i++){
        Desenfileirar(Fila, &produto);
    }
    free(Fila->frente);
}

TCelula* PesquisarFila(TFila * Fila, int codigo){
    TProduto produto;
    int n = Fila->tamanho;
    for(int i=0; i<n; i++){
        Desenfileirar(Fila, &produto);
        int q = Fila->frente->item.codigo;
        if(q == codigo){
            ImprimirProduto(produto);
        }
        Enfileirar(produto, Fila);
    }
}


