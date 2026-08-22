/* Implemente uma função void inverter(int *v, int n) que receba um vetor
de inteiros e seu tamanho e inverta a ordem de seus elementos.
A função deve modificar o próprio vetor, sem criar outro vetor auxiliar */

#include <stdio.h>
#include <stdlib.h>

void inverter(int *v, int n);

int main()
{
    int v[4];

    for (int i = 0; i <= 4; i++)
    {
        printf("Informe o valor do vetor v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    inverter(v, 4);
}

void inverter(int *v, int n)
{
    int guardaValor0, guardaValor1, guardaValor2, guardaValor3, guardaValor4;
    guardaValor0 = *v;
    guardaValor1 = *(v + 1);
    guardaValor2 = *(v + 2);
    guardaValor3 = *(v + 3);
    guardaValor4 = *(v + 4);

    *v = guardaValor4;
    *(v + 1) = guardaValor3;
    *(v + 2) = guardaValor2;
    *(v + 3) = guardaValor1;
    *(v + 4) = guardaValor0;

    for (int c = 0; c <= n; c++)
    {
        printf("Valor vetor v[%d]: %d\n", c, v[c]);
    }
}