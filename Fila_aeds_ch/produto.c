#include "produto.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
        //PERGUNTAR O ALEXNDRE MAGNO OU OS MONITORES COMO ACESSAR O CODIGO
        int q = Fila->frente->item.codigo;
        if(q == codigo){
            ImprimirProduto(produto);
        }
        Enfileirar(produto, Fila);
    }
}

//NUMERO 1 TAD FILA
int mesmosElementos(TFila * Fila1, TFila * Fila2){
    TProduto item;
    if(Fila1->tamanho != Fila2->tamanho){
        return 0;
    }
    for(int i=0; i<Fila1->tamanho; i++){
        //provavelmente precisa enfileirar
        Enfileirar(item, Fila1);
        Enfileirar(item, Fila2);
        if(Fila1->frente->item.codigo != Fila2->frente->item.codigo){
            return 0;
        }
        Desenfileirar(Fila1,&item);
        Desenfileirar(Fila2,&item);
    }
    return 1;
}

//NUMERO 2 TAD FILA
void removeEnesimo(TFila * Fila, int n){

    TProduto x;
    TFila FilaAux;
    FFVazia(&FilaAux);
    int p = Fila->tamanho;
    for(int i = 0; i<= p; i++){
        if(i==n){
            Desenfileirar(Fila, &x);
        }else{
            Desenfileirar(Fila,&x);
            Enfileirar(x,&FilaAux);
        }
    }
    while(!FVazia(FilaAux)){
        Desenfileirar(&FilaAux,&x);
        Enfileirar(x, Fila);
    }
}
//NUMERO 3 TAD FILA

int contem(TFila F1, int valor){
    TCelula * aux;
    aux =  F1.frente;
    while(aux!=NULL){
        if(aux->item.codigo == valor){
            return 1;
        }
        aux = aux->prox;
    }
}

void Intersecao(TFila Fila1, TFila Fila2, TFila Fila3){
    TCelula * aux;
    aux = Fila1.frente;
    while(aux!=NULL){
        if (contem(Fila2, aux->item.codigo)){
            Enfileirar(aux->item, &Fila3);
        }
        aux = aux->prox;
    }
}
//NUMERO 4 TAD FILA
void Diferenca(TFila Fila1, TFila Fila2, TFila Fila3){
    TCelula * aux;
    aux = Fila1.frente;
    while(aux!=NULL){
        if (!contem(Fila2, aux->item.codigo)){
            Enfileirar(aux->item, &Fila3);
        }
        aux = aux->prox;
    }
}

//NUMERO 5 TAD FILA
// nao consegui em pouco tempo desenvolver essa questão, me atrasei com os feriados mas recuperarei com certeza.

//produtos
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
