#ifndef PILHA_H
#define PILHA_H

typedef struct
{
    char carac[100];
} Elem;

typedef struct Nodo
{
    Elem info;
    struct Nodo *prox;
} Nodo;

typedef struct
{
    Nodo *topo;
    int quantidade;
} Pilha;

void reset(Pilha *pilha);
int empty(Pilha *pilha);
void push(Pilha *pilha, Elem elem);
Elem pop(Pilha *pilha);
int size(Pilha *pilha);
void top(Pilha *pilha);
void clear(Pilha *pilha);
void print(Pilha *pilha);

#endif