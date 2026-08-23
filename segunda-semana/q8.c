/* Implemente uma função void min_max(int *v, int n, int *min, int *max)
que receba um vetor de inteiros e seu tamanho e armazene, nas variáveis apontadas
por min e max, o menor e o maior elemento do vetor.*/

#include <stdio.h>
#include <stdlib.h>

void min_max(int *v, int n, int *min, int *max);

int main()
{
    int tamanhoVetor;
    int minFuncao, maxfuncao;

    printf("Infome o tamanho do vetor: ");
    scanf("%d", &tamanhoVetor);

    int v[tamanhoVetor];

    for (int i = 0; i < tamanhoVetor; i++)
    {
        printf("Informe o valor do vetor v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    min_max(v, tamanhoVetor, &minFuncao, &maxfuncao);
}

void min_max(int *v, int n, int *min, int *max)
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            *min = *v;
            *max = *v;
        }
        else
        {
            if (*min > *(v + i))
            {
                *min = *(v + i);
            }

            if (*max < *(v + i))
            {
                *max = *(v + i);
            }
        }
    }

    printf("Maximo dentro do vetor: %d\n", *max);
    printf("Minimo dentro do vetor: %d\n", *min);
}