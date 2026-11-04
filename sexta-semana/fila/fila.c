#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila
{
    Elem *inicio;
    Elem *fim;
    int quantidade;
};

void reset(Fila *fila)
{
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->quantidade = 0;
}

int empty(Fila *fila)
{
    return fila->quantidade == 0;
}

int size(Fila *fila)
{
    return fila->quantidade;
}

void enqueue(Fila *fila, Elem elem)
{
    Elem *novoElemento = malloc(sizeof(Elem));
    if (novoElemento == NULL)
    {
        return;
    }

    *novoElemento = elem;
    novoElemento->proximo = NULL;

    if (empty(fila))
    {
        fila->inicio = novoElemento;
    }
    else
    {
        fila->fim->proximo = novoElemento;
    }

    fila->fim = novoElemento;
    fila->quantidade++;
}

Elem dequeue(Fila *fila)
{
    Elem *aux;
    Elem elemento = {0}; // Porque foi declarado assim? Para retornar algo quando a lista for vazia? Evitar null-pointer?

    if (empty(fila))
    {
        return elemento;
    }

    aux = fila->fim; // Recebe o endereço do primeiro elemento (aquele que vai sair da fila)
    elemento = *aux; // Pega o conteúdo do ponteiro (o primeiro da lista) e salva no elemento para poder liberar a memória e não perder os dados

    fila->inicio = fila->inicio->proximo;

    if (fila->inicio == NULL)
    {
        fila->fim == NULL;
    }

    free(aux);
    fila->quantidade--;

    return elemento;
}

void front(Fila *fila)
{
    if (empty(fila))
    {
        return;
    }

    printf("%d\n", fila->inicio->valor);
}

void clear(Fila *fila)
{
    while (!empty(fila))
    {
        dequeue(fila);
    }
}

void print(Fila *fila)
{
    if (empty(fila))
    {
        printf("Fila vazia!\n");
        return;
    }

    Elem *aux = fila->inicio;
    printf("Fila:\n");

    while (aux != NULL)
    {
        printf("[%d]", aux->valor);
        aux = aux->proximo;
    }

    printf("\n");
}