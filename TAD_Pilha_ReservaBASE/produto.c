#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "produto.h"
#include <math.h>


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
//aqui eu coloquei o parametro como fila, e fiz toda a conversão de Fila pra pilha e toda a logica certinha
//e por mais que eu modifiquei as bibliotecas para que funcionassem pilhas e filas, o meu nao reconheceu o tipo fila.
//enfim, se for desconsiderar alguma coisa, por favor, desconsidere pouco rssrsrs
void InverteParte(int k, TPilha * Pilha)
{
    TPilha PilhaAux;
    TPilha PilhaAux2;
    TPilha PilhaAux3;
    TProduto x;
    FPVazia(&PilhaAux);
    FPVazia(&PilhaAux2);
    FPVazia(&PilhaAux3);

    while(!VPVazia(*Pilha))
    {
        Desempilha(Pilha,&x);
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
        Empilha(x,Pilha);
    }
    ImprimirPilha(Pilha);
    free(PilhaAux.topo);
    free(PilhaAux2.topo);
    free(PilhaAux3.topo);
}

//exercicio2
void ConversaoDeBase(int numero, int base)
{
    TPilha Pilha;
    FPVazia(&Pilha);
    TProduto x;
    while(numero >= 1)
    {
        int resto = numero % base;
        numero = numero/base;
        x.codigo = resto;
        Empilha(x,&Pilha);
    }
    while(!VPVazia(Pilha))
    {
        Desempilha(&Pilha,&x);
        printf("%d", x.codigo);
    }
    printf("\n");
}

//exercicio 3
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
            if(Fonte->topo->item.codigo < Destino.topo->item.codigo)
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
        if(i%3 ==2)
        {
            if(VPVazia(*Fonte))
            {
                Desempilha(&Aux, &produto);
                Empilha(produto,Fonte);
            }
            if(Fonte->topo->item.codigo < Aux.topo->item.codigo)
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
        if(i%3 ==0)
        {
            if(VPVazia(Aux))
            {
                Desempilha(&Destino, &produto);
                Empilha(produto,&Aux);
            }
            if(Aux.topo->item.codigo < Destino.topo->item.codigo)
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

//exercicio 4
void ParesParenteses(char * caracteres)
{
    TPilha Pilha;
    TProduto x;
    int contador = 0;
    FPVazia(&Pilha);
    int tamanhoString = strlen(caracteres);
    for(int i =0; i<tamanhoString; i++)
    {
        if(caracteres[i] == '(')
        {
            x.caracter = caracteres[i];
            Empilha(x,&Pilha);
        }
        if(x.caracter == '(' && caracteres[i] == ')')
        {
            Desempilha(&Pilha,&x);
            x.caracter ='\0';
            contador = contador +2;
        }
    }
    printf("Numero de parenteses com par = %d\n", contador);
    free(Pilha.topo);
}

//exercicio 5
void ParentesesMultiplos(char * caracteres)
{
    TPilha Pilha;
    TProduto x;
    int contador =0;
    FPVazia(&Pilha);
    int tamanhoString = strlen(caracteres);
    for(int i =0; i<tamanhoString; i++)
    {
        if(caracteres[i] == '(')
        {

            x.caracter = caracteres[i];
            Empilha(x,&Pilha);
        }
        if(caracteres[i] == ')')
        {
            Desempilha(&Pilha,&x);
            if(Pilha.tamanho >=2 && Pilha.topo->item.caracter == '(' && Pilha.topo->prox->item.caracter == '(' && Pilha.topo->prox->prox->item.caracter == '(')
            {
                //printf("A expressao EH cercada por parenteses multiplos.\n");
                contador++;
            }
        }
    }

    if(contador == 0){
        printf("A expressao NAO EH cercada por parenteses multiplos.\n");
    }else{
        printf("A expressao EH cercada por parenteses multiplos.\n");
    }
    free(Pilha.topo);
}
