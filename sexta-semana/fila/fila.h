#ifndef FILA_H
#define FILA_H

typedef struct
{
    int valor;
    Elem *proximo; // Ponteiro para o próximo elemento
} Elem;

typedef struct
{
    Elem *inicio;
    Elem *fim;
    int quantidade;
} Fila;

void reset(Fila *fila);
int empty(Fila *fila);
int size(Fila *fila);
void enqueue(Fila *fila, Elem elem);
Elem dequeue(Fila *fila);
void front(Fila *fila);
void clear(Fila *fila);
void print(Fila *fila);

#endif