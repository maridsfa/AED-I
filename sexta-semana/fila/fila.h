#ifndef FILA_H
#define FILA_H

typedef struct elem Elem;

typedef struct elem
{
    int valor;
    Elem *proximo;
} Elem;

typedef struct fila Fila;

Fila *reset();
int empty(Fila *fila);
int size(Fila *fila);
void enqueue(Fila *fila, Elem elem);
Elem dequeue(Fila *fila);
void front(Fila *fila);
void clear(Fila *fila);
void print(Fila *fila);
Elem retornaMaiorValor(Fila *fila);

#endif