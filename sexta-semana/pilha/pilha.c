#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void reset(Pilha *pilha)
{
    pilha->topo = NULL;
    pilha->quantidade = 0;

    // não deveria liberar a memória dos nós antes de resetar? se houver algum?
}

int empty(Pilha *pilha)
{
    return pilha->quantidade == 0;
    // a validação poderia ser pelo elemento que o topo aponta? exemplo: vazia == null?
}

void push(Pilha *pilha, Elem elem)
{
    Nodo *novo = malloc(sizeof(Nodo));

    if (novo == NULL)
    {
        printf("ERRO AO ALOCAR MEMÓRIA\n");
        return;
    }

    novo->info = elem;
    novo->prox = pilha->topo; // O novo elemento aponta para onde o topo apontava.
    pilha->topo = novo;       // O topo aponta agora apra o novo elemento.

    pilha->quantidade++;

    return;
}

Elem pop(Pilha *pilha)
{
    Nodo *aux;
    Elem itemRemovido;

    Elem itemVazio = {'\0'}; // Retorno padrão para caso de erro

    if (empty(pilha))
    {
        printf("PILHA VAZIA!\n");
        return itemVazio;
    }

    aux = pilha->topo;
    itemRemovido = aux->info;

    pilha->topo = aux->prox;
    pilha->quantidade--;
    free(aux);

    return itemRemovido;
}

int size(Pilha *pilha)
{
    return pilha->quantidade;
}

void top(Pilha *pilha)
{
    if (empty(pilha))
    {
        printf("PILHA VAZIA\n");
        return;
    }

    printf("Topo: %s\n", pilha->topo->info.carac);
}

void clear(Pilha *pilha)
{
    while (!empty(pilha))
    {
        pop(pilha);
    }
}

void print(Pilha *pilha)
{
    if (empty(pilha))
    {
        printf("Pilha Vazia\n");
        return;
    }

    Nodo *atual = pilha->topo;
    printf("Pilha: ");
    while (atual != NULL)
    {
        printf("[%s] ", atual->info.carac); // Usamos %s aqui também
        atual = atual->prox;
    }
    printf("\n");
}
