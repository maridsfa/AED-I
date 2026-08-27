/* Implemente um programa que leia uma quantidade indefinida de números inteiros e armazene os valores em um vetor dinâmico. O programa deve começar com espaço para um único elemento e aumentar o espaço alocado para o vetor a cada novo valor inserido. A leitura deve terminar quando o usuário digitar -1.

Ao final, o programa deve:
● mostrar os valores armazenados;
● mostrar a quantidade de elementos;
● mostrar o maior e o menor valor;
● liberar a memória utilizada.
 */

#include <stdio.h>
#include <stdlib.h>

void min_max(int *v, int n, int *min, int *max);

int main()
{
    int numero, totalAlocados = 0;
    int *vetorAlocado;
    int minFuncao, maxfuncao;

    do
    {
        printf("Informe um numero: ");
        scanf("%d", &numero);

        if (numero == -1)
        {
            break;
        }
        else
        {
            if (totalAlocados == 0)
            {
                vetorAlocado = malloc(sizeof(int));
                *vetorAlocado = numero;
                totalAlocados++;
            }
            else
            {
                vetorAlocado = realloc(vetorAlocado, (totalAlocados + 1) * sizeof(int));
                *(vetorAlocado + totalAlocados) = numero;
                totalAlocados++;
            }
        }

    } while (numero != -1);

    printf("Quantidade de elementos alocados: %d\n", totalAlocados);

    for (int i = 0; i < totalAlocados; i++)
    {
        printf("V[%d]: %d\n", i, vetorAlocado[i]);
    }

    min_max(vetorAlocado, totalAlocados, &minFuncao, &maxfuncao);

    free(vetorAlocado);
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