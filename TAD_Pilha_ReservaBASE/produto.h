#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "util.h"

// produto se refere a Pilha

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
void InverteParte(int k, TPilha * Pilha);
//exercicio2
void ConversaoDeBase(int numero, int base);
//exercicio 3
void torreHanoi(TPilha * Fonte, int numDiscos);
//exercicio 4
void ParesParenteses(char * caracteres);
//exercicio 5
void ParentesesMultiplos(char * caracteres);

#endif // PRODUTO_H_INCLUDED
