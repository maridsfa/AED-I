#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void incorporaElementos(Head *primeiraLista, Head *segundaLista);

int main()
{
    Head *primeiraLista = criaLista();
    Head *segundaLista = criaLista();

    Dados primeiroDado;
    Dados segundoDado;
    char continuarPrimeiraLista = 's';

    while (continuarPrimeiraLista == 's' || continuarPrimeiraLista == 'S')
    {
        printf("-- LISTA 1 --\n");
        printf("Codigo: ");
        scanf("%d", &primeiroDado.cod);

        inserirFinal(primeiraLista, primeiroDado);

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &continuarPrimeiraLista);
    }

    char continuarSegundaLista = 's';

    while (continuarSegundaLista == 's' || continuarSegundaLista == 'S')
    {
        printf("-- LISTA 2 --\n");
        printf("Codigo: ");
        scanf("%d", &segundoDado.cod);

        inserirFinal(segundaLista, segundoDado);

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &continuarSegundaLista);
    }

    incorporaElementos(primeiraLista, segundaLista);
    imprimirLista(primeiraLista);

    liberaLista(primeiraLista);
    liberaLista(segundaLista);
}

void incorporaElementos(Head *primeiraLista, Head *segundaLista)
{
    if (segundaLista->pFirst == NULL)
    {
        return; // nenhum novo elemento para ser incorporado na primeira losta
    }

    if (primeiraLista->pFirst == NULL)
    {
        primeiraLista->pFirst = segundaLista->pFirst;
        segundaLista->pFirst = NULL;
        return;
    }

    Nodo *auxPrimeiraLista = primeiraLista->pFirst;

    while (auxPrimeiraLista->prox != NULL)
    {
        auxPrimeiraLista = auxPrimeiraLista->prox;
    }

    auxPrimeiraLista->prox = segundaLista->pFirst;

    // deixa a segunda lista vazia
    segundaLista->pFirst = NULL;
}
