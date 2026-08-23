/* Implemente uma função void troca_vizinhos(int *a, int *b) que receba os
endereços de dois elementos consecutivos de um vetor e troque os valores desses
elementos. Em seguida, escreva um programa que percorra um vetor de inteiros e
utilize a função para trocar os elementos do vetor dois a dois. Considere que o vetor
possui tamanho par. */

#include <stdio.h>
#include <stdlib.h>

void troca_vizinhos(int *a, int *b);

int main()
{
    int v[4];

    for (int i = 0; i < 4; i++)
    {
        printf("Informe o valor do vetor v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    for (int c = 0; c < 4; c++)
    {
        if (c % 2 == 0)
        {
            troca_vizinhos(&v[c], &v[c + 1]);
        }
    }

    for (int d = 0; d < 4; d++)
    {
        printf("Valor vetor v[%d]: %d\n", d, v[d]);
    }
}

void troca_vizinhos(int *a, int *b)
{
    int aux = 0;
    aux = *a;
    *a = *b;
    *b = aux;
}
