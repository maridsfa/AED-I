/* Escreva um programa que leia uma string e utilize a pilha para gerar a string invertida. 
O programa deve exibir a string original e sua respectiva sequência invertida. */

#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main()
{
    Pilha pilha;
    reset(&pilha);

    char entrada[100];
    char invertida[100];
    Elem elemento;
    int i = 0;

    printf("Entrada: ");
    scanf(" %[^\n]", entrada);

    // Empilha cada caractere da string original
    for (i = 0; entrada[i] != '\0'; i++)
    {
        elemento.carac[0] = entrada[i];
        elemento.carac[1] = '\0';
        push(&pilha, elemento);
    }

    // Desempilha os caracteres construindo a nova string invertida
    int index = 0;
    while (!empty(&pilha))
    {
        elemento = pop(&pilha);
        invertida[index] = elemento.carac[0];
        index++;
    }

    invertida[index] = '\0';

    printf("Saida: %s\n", invertida);

    clear(&pilha); // Libera os recursos alocados
    return 0;
}