/* Escreva um programa que leia uma palavra e utilize uma pilha para verificar se ela é um palíndromo.
Uma palavra é considerada um palíndromo quando apresenta a mesma sequência de caracteres tanto da esquerda para a direita quanto
da direita para a esquerda.
Ao final, o programa deve informar se a palavra fornecida é ou não um palíndromo. */

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

    printf("Entrada: ");
    scanf(" %[^\n]", entrada);

    for (int i = 0; entrada[i] != '\0'; i++)
    {
        elemento.carac[0] = entrada[i];
        elemento.carac[1] = '\0';
        push(&pilha, elemento);
    }

    int index = 0;
    while (!empty(&pilha))
    {
        elemento = pop(&pilha);
        invertida[index] = elemento.carac[0];
        index++;
    }

    invertida[index] = '\0';

    if (strcmp(entrada, invertida) == 0)
    {
        printf("Palindromo");
    }
    else
    {
        printf("Nao eh palindromo");
    }

    clear (&pilha);
}