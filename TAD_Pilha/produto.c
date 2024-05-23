#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "produto.h"
#include <math.h>
#include "fila.h"


//-----------------------------------------
//PILHAS

void FPVazia(TPilha * Pilha)
{
    Pilha->topo = (TCelula *) malloc (sizeof(TCelula));
    Pilha->fundo = Pilha->topo;
    Pilha->topo->prox = NULL;
    Pilha->tamanho = 0;
}

int VPVazia(TPilha Pilha)
{
    return (Pilha.topo == Pilha.fundo);
}

void Empilha(TProduto Produto, TPilha * Pilha)
{
    TCelula * Aux;
    Aux = (TCelula*) malloc (sizeof(TCelula));
    Pilha->topo->item = Produto;
    Aux->prox = Pilha->topo;
    Pilha->topo = Aux;
    Pilha->tamanho++;
}

void Desempilha(TPilha * Pilha, TProduto * Item)
{
    TCelula * q;
    if(VPVazia(*Pilha))
    {
        printf("Erro: Lista Vazia!");
        return;
    }
    q = Pilha->topo;
    Pilha->topo = q->prox;
    *Item = q->prox->item;
    free(q);
    Pilha->tamanho--;
}

void ImprimirPilha(TPilha * Pilha)
{
    TPilha PilhaAux;
    TProduto x;
    FPVazia(&PilhaAux);

    while(!VPVazia(*Pilha))
    {
        Desempilha(Pilha,&x);
        Empilha(x, &PilhaAux);
    }
    while(!VPVazia(PilhaAux))
    {
        Desempilha(&PilhaAux, &x);
        ImprimirProduto(x);
        Empilha(x,Pilha);
    }
    free(PilhaAux.topo);
}

int PesquisarPilha(TPilha * Pilha, TProduto *Produto)
{
    TPilha PilhaAux;
    FPVazia(&PilhaAux);
    TProduto y;
    y = Pilha->topo->item;
    int achou =0;

    while(!VPVazia(*Pilha))
    {
        Desempilha(Pilha,&y);
        Empilha(y, &PilhaAux);
    }
    while(!VPVazia(PilhaAux))
    {
        Desempilha(&PilhaAux,&y);
        int confere = strcmp(PilhaAux.topo->item.nome, Produto->nome);
        if(confere == 0) // 0 -> econtrou
        {
            *Produto = y;
            achou = 1;
        }
        Empilha(y, Pilha);
    }
    free(PilhaAux.topo);

    if(achou ==1)
    {
        return 1;
    }
    else
    {
        Produto->codigo = -1;
        return 0;
    }
}

void LiberarPilha(TPilha *Pilha)
{
    TProduto Produto;
    while(!VPVazia(*Pilha))
    {
        Produto = Pilha->topo->prox->item;
        Desempilha(Pilha,&Produto);
    }
    free(Pilha->topo);
}

//exercicio 1
//trocar pilha por listas
void InverteParte(int k, TFila * Fila)
{
    TPilha Pilha;
    TPilha PilhaRecebe;
    TPilha PilhaAux;
   .TPilha PilhaAux2;
    TPilha PilhaAux3;
    TProduto x;
    FPVazia(&PilhaRecebe);
    FPVazia(&Pilha);
    FPVazia(&PilhaAux);
    FPVazia(&PilhaAux2);
    FPVazia(&PilhaAux3);

    //Pilha recebendo produtos da fila
    while(!FVazia(*Fila)){
        Desenfileirar(Fila,&x);
        Empilha(x,&PilhaRecebe);
    }

    //invertendo k-esimos produtos
    while(!VPVazia(Pilha))
    {
        Desempilha(&Pilha,&x);
        Empilha(x, &PilhaAux);
    }

    for(int i = 0; i<k; i++)
    {
        Desempilha(&PilhaAux, &x);
        Empilha(x, &PilhaAux2);
    }

    while(!VPVazia(PilhaAux))
    {
        Desempilha(&PilhaAux, &x);
        Empilha(x,&PilhaAux3);
    }

    while(!VPVazia(PilhaAux2))
    {
        Desempilha(&PilhaAux2,&x);
        Empilha(x,&PilhaAux);
    }
    while(!VPVazia(PilhaAux3))
    {
        Desempilha(&PilhaAux3,&x);
        Empilha(x,&PilhaAux2);
    }
    while(!VPVazia(PilhaAux2))
    {
        Desempilha(&PilhaAux2, &x);
        Empilha(x,&PilhaAux);
    }
    while(!VPVazia(PilhaAux))
    {
        Desempilha(&PilhaAux, &x);
        Empilha(x,&PilhaAux3);
    }
    while(!VPVazia(PilhaAux3))
    {
        Desempilha(&PilhaAux3, &x);
        Empilha(x,&Pilha);
    }

    while(VPVazia(Pilha)){
        Desempilha(&Pilha,&x);
        Enfileirar(x,Fila);
    }

    ImprimirPilha(&Pilha);
    ImprimirFIla(Fila);
    free(Pilha.topo).
    free(PilhaRecebe.topo);
    free(PilhaAux.topo);
    free(PilhaAux2.topo);
    free(PilhaAux3.topo);
}



//exercicio 3 torre de hanoi
//conferir o que ta errado nos -> e .
//além de conferir se esta certa
/*
void torreHanoi(TPilha * Fonte, int numDiscos)
{
    TPilha Aux;
    TPilha Aux2;
    TPilha Destino;
    FPVazia(&Aux);
    FPVazia(&Aux2);
    FPVazia(&Destino);

    TProduto produto;

    if(numDiscos % 2 == 0)
    {
        Aux2 = Destino;
        Destino = Aux;
        Aux = Aux2;
    }

    int numMovimentos = pow(2, numDiscos) - 1;

    for(int i = 0; i<numMovimentos; i++)
    {
        if(i%3 == 1)
        {
            if(VPVazia(*Fonte))
            {
                Desempilha(&Destino, &produto);
                Empilha(produto,Fonte);
            }
            if(Fonte->topo->item->codigo < Destino->topo->item.codigo)
            {
                Desempilha(Fonte, &produto);
                Empilha(produto,&Destino);
            }
            else
            {
                Desempilha(&Destino, &produto);
                Empilha(produto,Fonte);
            }
        }
        if(i%3 ==2){
            if(VPVazia(*Fonte))
            {
                Desempilha(&Aux, &produto);
                Empilha(produto,Fonte);
            }
            if(Fonte->topo->item.codigo < Aux->topo->item.codigo)
            {
                Desempilha(Fonte, &produto);
                Empilha(produto,&Aux);
            }
            else
            {
                Desempilha(&Aux, &produto);
                Empilha(produto,Fonte);
            }
        }
        if(i%3 ==0){
            if(VPVazia(Aux))
            {
                Desempilha(&Destino, &produto);
                Empilha(produto,&Aux);
            }
            if(Aux->topo->item.codigo < Destino->topo->item.codigo)
            {
                Desempilha(&Aux, &produto);
                Empilha(produto,&Destino);
            }
            else
            {
                Desempilha(&Destino, &produto);
                Empilha(produto,&Aux);
            }
        }
    }
}
*/
