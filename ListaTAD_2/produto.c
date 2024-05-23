#include "produto.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void FLVazia(TLista * Lista)
{
    Lista->primeiro = (TCelula*) malloc(sizeof(TCelula));
    Lista-> ultimo = Lista->primeiro;
    Lista->primeiro->prox = NULL;
    Lista->tamanho = 0;
}

int Vazia(TLista Lista)
{
    return (Lista.primeiro == Lista.ultimo);
}

void Inserir(TProduto x, TLista * Lista)
{
    Lista->ultimo->prox = (TCelula*) malloc(sizeof(TCelula));
    Lista->ultimo = Lista->ultimo->prox;
    Lista->ultimo->item = x;
    Lista->ultimo->prox = NULL;
    Lista->tamanho++;
}

void ImprimirProduto(TProduto x)
{
    printf("\n Codigo: %d", x.codigo);
    printf("\n Nome: %s", x.nome);
    printf(" Descricao: %s", x.descricao);
    printf(" Peso: %.2f", x.peso);
    printf("\n Preco: %.2f", x.preco);
}

void Imprimir(TLista Lista)
{
    printf("\nLista impressa:");
    TCelula * Aux;
    Aux = Lista.primeiro->prox;
    while(Aux!=NULL)
    {
        ImprimirProduto(Aux->item);
        Aux = Aux->prox;
        printf("\n");
    }
}

TCelula * Pesquisar(TLista Lista, TProduto Item)
{
    TCelula * Aux;
    Aux = Lista.primeiro;
    while(Aux->prox != NULL)
    {
        if(Aux->prox->item.codigo == Item.codigo)
        {
            return Aux;
        }
        Aux = Aux->prox;
    }
    return NULL;
}

void Excluir (TLista * Lista, TProduto * Item)
{
    TCelula * Aux1;
    TCelula * Aux2;
    Aux1 = Pesquisar(*Lista, *Item);
    if(Aux1 != NULL)
    {
        Aux2 = Aux1->prox;
        Aux1->prox = Aux2->prox;
        *Item = Aux2->item;
        if(Aux1->prox == NULL)
        {
            Lista->ultimo = Aux1;
        }
        free(Aux2);
        Lista->tamanho--;
    }
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

void Liberar(TLista * Lista)
{
    TCelula * aux;
    aux = Lista->primeiro;
    while (aux!=NULL)
    {
        TLista * lista = aux->prox;
        free(aux);
        aux=lista;
    }
}

bool comparaListas(TLista Lista1, TLista Lista2)
{
    TCelula* Aux1;
    Aux1 = Lista1.primeiro -> prox;

    TCelula* Aux2;
    Aux2 = Lista2.primeiro -> prox;

    while (Aux1 != NULL && Aux2 != NULL)
    {
        if(Aux1->item.codigo != Aux2->item.codigo)
        {
            return false;
        }

        Aux1 = Aux1->prox;
        Aux2 = Aux2->prox;
    }
    return Aux1 == NULL && Aux2 == NULL;
}

void concatenarListas(TLista* lista1, TLista* lista2)
{
    TCelula * Aux;
    if (lista1 == NULL)
    {
        lista1 = lista2;
        return;
    }
    Aux = lista1;
    while (Aux->prox != NULL)
    {
        Aux = Aux->prox;
    }
    Aux->prox = lista2;
}

void imprimirIesimo(TLista Lista, int numero)
{
    TCelula* Aux;
    Aux = Lista.primeiro -> prox;

    int auxiliar = 1;

    while (Aux != NULL)
    {
        if(auxiliar != numero)
        {
            auxiliar++;
            Aux = Aux -> prox;
        }
        else
        {
            printf("o elemento da celula pesquisada eh: %d\n", Aux->item);
            break;
        }
    }
}

void excluirEnesimo(TLista *Lista, int numero)
{
    TCelula *Aux1, *Aux2;
    TProduto Item;
    Aux1 = Pesquisar(*Lista, Item);
    if (Aux1 != NULL)
    {
        Aux2 = Aux1->prox;
        Aux1->prox = Aux2 -> prox;
        Item = Aux2->item;
        if (Aux1->prox == NULL)
            Lista->ultimo = Aux1;
        free(Aux2);
        Lista->tamanho--;
    }
}

void dividirLista(TLista *listaPrincipal, TLista *lista1, TLista *lista2)
{
    int i;

    lista1->tamanho = listaPrincipal->tamanho / 2;
    lista2->tamanho = listaPrincipal->tamanho - lista1->tamanho;

    for (i = 0; i < lista1->tamanho; i++)
    {
        lista1->ultimo->prox = (TCelula*) malloc(sizeof(TCelula));
        lista1->ultimo = lista1->ultimo->prox;
        lista1->ultimo->item = listaPrincipal->primeiro->item;
        lista1->ultimo->prox = NULL;
        lista1->tamanho++;
    }


    for(i=0; i<lista1->tamanho; i++)
    {
        TCelula * Auxi;
        Auxi = listaPrincipal->primeiro;
        Excluir(listaPrincipal,Auxi->prox);
        Auxi = Auxi->prox;
    }

    for (i = lista1->tamanho; i < listaPrincipal->tamanho; i++)
    {
        lista2->ultimo->prox = (TCelula*) malloc(sizeof(TCelula));
        lista2->ultimo = lista2->ultimo->prox;
        lista2->ultimo->item = listaPrincipal->primeiro->item;
        lista2->ultimo->prox = NULL;
        lista2->tamanho++;
    }
}
