#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "util.h"
#include "produto.h"
#include "interface.h"

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


#endif // FILA_H_INCLUDED
