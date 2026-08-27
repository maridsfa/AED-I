/*
Implemente uma função int *concatenar(int *v1, int n1, int *v2, int n2, int *n3) que receba dois vetores de inteiros e seus respectivos tamanhos, aloque dinamicamente um novo vetor contendo os elementos dos dois vetores em sequência e armazene em n3 o tamanho do novo vetor.

Atenção: Aloque dinamicamente os vetores v1 e v2
Ao final, o programa deve liberar a memória dos vetores v1, v2 e do novo vetor.
*/

#include <stdio.h>
#include <stdlib.h>

int *concatenar(int *v1, int n1, int *v2, int n2, int *n3);

int main()
{
    int tamanhoVetor1, tamanhoVetor2, tamanhoVetor3;

    printf("Infome o tamanho do vetor 1: ");
    scanf("%d", &tamanhoVetor1);

    int *v1 = malloc(tamanhoVetor1 * sizeof(int));

    for (int i = 0; i < tamanhoVetor1; i++)
    {
        printf("Informe o valor do primeiro vetor v[%d]: ", i);
        scanf("%d", &v1[i]);
    }

    printf("Infome o tamanho do vetor 2: ");
    scanf("%d", &tamanhoVetor2);

    int *v2 = malloc(tamanhoVetor2 * sizeof(int));

    for (int d = 0; d < tamanhoVetor2; d++)
    {
        printf("Informe o valor do segundo vetor v[%d]: ", d);
        scanf("%d", &v2[d]);
    }

    int *novoVetor = concatenar(v1, tamanhoVetor1, v2, tamanhoVetor2, &tamanhoVetor3);

    printf("Novo vetor alocado:\n");
    for (int m = 0; m < tamanhoVetor3; m++)
    {
        printf("v[%d]: %d\n", m, *(novoVetor + m));
    }

    free(v1);
    free(v2);
    free(novoVetor);
}

int *concatenar(int *v1, int n1, int *v2, int n2, int *n3)
{
    *n3 = n1 + n2;

    int *novoVetorAlocado = malloc(*n3 * sizeof(int));

    for (int c = 0; c < n1; c++)
    {
        *(novoVetorAlocado + c) = *(v1 + c);
    }

    for (int c = n1; c < n1 + n2; c++)
    {
        *(novoVetorAlocado + c) = *(v2 + (c - n1));
    }

    return novoVetorAlocado;
}