#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
    Fila *fila = reset();
    Elem primeiroElemento, segundoElemento, terceiroElemento;

    printf("Informe o primeiro elemento: ");
    scanf("%d", &primeiroElemento.valor);
    enqueue(fila, primeiroElemento);

    printf("Informe o segundo elemento: ");
    scanf("%d", &segundoElemento.valor);
    enqueue(fila, segundoElemento);

    printf("Informe o terceiro elemento: ");
    scanf("%d", &terceiroElemento.valor);
    enqueue(fila, terceiroElemento);

    print(fila);

    Elem maiorValor = retornaMaiorValor(fila);
    printf("Maior valor: %d\n", maiorValor.valor);

    clear(fila);
    free(fila);

    return 0;
}