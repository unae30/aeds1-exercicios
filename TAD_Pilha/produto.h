#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util.h"
#include "fila.h"
#include "interface.h"

typedef struct{
    TCelula * fundo;
    TCelula * topo;
    int tamanho;
}TPilha;

void FPVazia(TPilha * Pilha);
int VPVazia(TPilha Pilha);
void Empilha(TProduto Produto, TPilha * Pilha);
void Desempilha (TPilha * Pilha, TProduto * Item);
void ImprimirPilha(TPilha * Pilha);
int PesquisarPilha(TPilha * Pilha, TProduto *Produto);
void LiberarPilha(TPilha *Pilha);
//exercicio 1
void InverteParte(int k, TFila * Fila);


#endif // PRODUTO_H_INCLUDED
