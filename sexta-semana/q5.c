/* Escreva um programa que leia uma string e utilize uma pilha para remover caracteres repetidos consecutivamente.
O programa deve percorrer a string e, sempre que encontrar caracteres iguais em sequência, manter apenas uma ocorrência.
Ao final, o programa deve exibir a string resultante. */

#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main()
{
    Pilha pilha;
    reset(&pilha);

    char entrada[100];
    char corrigida[100];
    Elem elemento;

    printf("Entrada: ");
    scanf(" %[^\n]", entrada);

    for (int i = 0; entrada[i] != '\0'; i++)
    {
        if (empty(&pilha) || entrada[i] != pilha.topo->info.carac[0])
        {
            elemento.carac[0] = entrada[i];
            elemento.carac[1] = '\0';
            push(&pilha, elemento);
        }
    }

    int tamanho = size(&pilha);
    corrigida[tamanho] = '\0'; // Fecha a string na posição correta

    int index = tamanho - 1; // Começa a preencher do último caractere válido (de trás para frente)
    while (!empty(&pilha))
    {
        elemento = pop(&pilha);
        corrigida[index] = elemento.carac[0];
        index--;
    }

    printf("Saida: %s\n", corrigida);

    clear(&pilha);
}
