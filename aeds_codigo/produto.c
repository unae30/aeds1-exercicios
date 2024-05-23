#include "produto.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void FLVazia(TLista * Lista){
    Lista->primeiro = (TCelula*) malloc(sizeof(TCelula));
    Lista-> ultimo = Lista->primeiro;
    Lista->primeiro->prox = NULL;
    Lista->tamanho = 0;
}

int Vazia(TLista Lista){
    return (Lista.primeiro == Lista.ultimo);
}

void Inserir(TProduto x, TLista * Lista){
    Lista->ultimo->prox = (TCelula*) malloc(sizeof(TCelula));
    Lista->ultimo = Lista->ultimo->prox;
    Lista->ultimo->item = x;
    Lista->ultimo->prox = NULL;
    Lista->tamanho++;
}

void ImprimirProduto(TProduto x){
    printf("\n Codigo: %d", x.codigo);
    printf("\n Nome: %s", x.nome);
    printf(" Descricao: %s", x.descricao);
    printf(" Peso: %.2f", x.peso);
    printf("\n Preco: %.2f", x.preco);
}

void Imprimir(TLista Lista){
    printf("\nLista impressa:");
    TCelula * Aux;
    Aux = Lista.primeiro->prox;
    while(Aux!=NULL){
        ImprimirProduto(Aux->item);
        Aux = Aux->prox;
        printf("\n");
    }
}

TCelula * Pesquisar(TLista Lista, TProduto Item){
    TCelula * Aux;
    Aux = Lista.primeiro;
    while(Aux->prox != NULL){
        if(Aux->prox->item.codigo == Item.codigo){
            return Aux;
        }
        Aux = Aux->prox;
    }
    return NULL;
}

void Excluir (TLista * Lista, TProduto * Item){
    TCelula * Aux1;
    TCelula * Aux2;
    Aux1 = Pesquisar(*Lista, *Item);
    if(Aux1 != NULL){
        Aux2 = Aux1->prox;
        Aux1->prox = Aux2->prox;
        *Item = Aux2->item;
        if(Aux1->prox == NULL){
            Lista->ultimo = Aux1;
        }
        free(Aux2);
        Lista->tamanho--;
    }
}

void LerProduto(TProduto * x){
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

void Liberar(TLista * Lista){
    TCelula * aux;
    aux = Lista->primeiro;
    while (aux!=NULL){
            TLista * listaAux = aux->prox;
            free(aux);
            aux=listaAux;
    }
}


