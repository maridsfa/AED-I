#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Head *criaLista()
{
    Head *lista = (Head *)malloc(sizeof(Head));

    if (lista != NULL)
    {
        lista->pFirst = NULL;
    }

    return lista;
}

int listaVazia(Head *lista)
{
    if (lista->pFirst == NULL)
    {
        return 1;
    }
    return 0;
}

void inserirInicio(Head *lista, Dados dado)
{
    Nodo *novoElemento = (Nodo *)malloc(sizeof(Nodo));

    if (lista->pFirst == NULL)
    {
        novoElemento->info = dado;
        novoElemento->prox = NULL;
        lista->pFirst = novoElemento;
        return;
    }
    else
    {
        novoElemento->prox = lista->pFirst;
        lista->pFirst = novoElemento;
        novoElemento->info = dado;
    }
}

void inserirFinal(Head *lista, Dados dado)
{
    Nodo *novoElemento = (Nodo *)malloc(sizeof(Nodo));
    novoElemento->info = dado;
    novoElemento->prox = NULL;

    if (listaVazia(lista))
    {
        lista->pFirst = novoElemento;
        return;
    }
    else
    {
        Nodo *atual = lista->pFirst; // recebe o endereço do primeiro elemento da lista (depois da cabeça)

        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }

        atual->prox = novoElemento;
    }
}

int removerInicio(Head *lista)
{
    if (listaVazia(lista))
    {
        printf("LOG WARNING -> LISTA VAZIA!");
        return 0;
    }
    else
    {
        Nodo *remover = lista->pFirst;

        lista->pFirst = lista->pFirst->prox;

        free(remover);

        return 1;
    }
}

int removerFinal(Head *lista)
{
    if (listaVazia(lista))
    {
        return 0;
    }

    if (lista->pFirst->prox == NULL)
    {
        free(lista->pFirst);
        lista->pFirst = NULL;
        return 1;
    }

    Nodo *atual = lista->pFirst; // recebe o endereço do primeiro elemento da lista (depois da cabeça)

    while (atual->prox->prox != NULL)
    {
        atual = atual->prox;
    }

    Nodo *remover = atual->prox;

    atual->prox = NULL;

    free(remover);

    return 1;
}

int buscar(Head *lista, int cod, Dados *resultado)
{
    if (listaVazia(lista))
    {
        return 0;
    }

    Nodo *atual = lista->pFirst;

    while (atual != NULL)
    {
        if (atual->info.cod == cod)
        {
            *resultado = atual->info;
            return 1;
        }

        atual = atual->prox;
    }

    return 0;
}

void imprimirLista(Head *lista)
{
    if (listaVazia(lista))
    {
        return;
    }

    Nodo *atual = lista->pFirst;

    while (atual != NULL)
    {
        printf("Cod: %d\n", atual->info.cod);
        printf("Nome: %s\n", atual->info.nome);
        printf("Preco: %.2f\n", atual->info.preco);
        atual = atual->prox;
    }
}

void liberaLista(Head *lista)
{
    if (lista->pFirst->prox == NULL)
    {
        free(lista->pFirst);
        lista->pFirst = NULL;
    }

    Nodo *atual = lista->pFirst;

    while (atual != NULL)
    {
        Nodo *temp = atual->prox;
        free(atual);
        atual = temp;
    }
}
