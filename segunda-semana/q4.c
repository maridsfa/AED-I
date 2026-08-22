/* Dado o trecho abaixo, determine o valor impresso por cada printf, sem
executar o código. Em seguida, compile e execute o programa para conferir suas
respostas. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int v[5] = {2, 4, 6, 8, 10};
    int *p = v;
    printf("%d\n", *p); 
    printf("%d\n", *(p + 2));
    printf("%d\n", p[3]);
    printf("%d\n", *p + 1);
    printf("%d\n", *(v + 4));
}