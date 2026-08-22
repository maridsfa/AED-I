/* Implemente uma função int soma(int *v, int n) que receba um vetor de
inteiros e seu tamanho e retorne a soma de seus elementos. */

#include <stdio.h>
#include <stdlib.h>

int soma(int *v, int n);

int main()
{
    int tamanhoVetor;

    printf("Infome o tamanho do vetor: ");
    scanf("%d", &tamanhoVetor);

    int v[tamanhoVetor];

    for (int i = 0; i < tamanhoVetor; i++)
    {
        printf("Informe o valor do vetor v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    int somaVetor = 0;

    somaVetor = soma(v, tamanhoVetor);

    printf("Total soma: %d", somaVetor);
}

int soma(int *v, int n)
{
    int valorVetor = 0, soma = 0;

    for (int i = 0; i < n; i++)
    {
        valorVetor = *(v + i);
        soma = soma + valorVetor;
    }

    return soma;
}