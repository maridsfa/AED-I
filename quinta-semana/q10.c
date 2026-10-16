#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Head *copiaLista(Head *lista);

int main()
{
    Head *lista = criaLista();

    Dados primeiroDado;

    char continuarPrimeiraLista = 's';

    while (continuarPrimeiraLista == 's' || continuarPrimeiraLista == 'S')
    {
        printf("-- LISTA --\n");
        printf("Codigo: ");
        scanf("%d", &primeiroDado.cod);

        inserirFinal(lista, primeiroDado);

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &continuarPrimeiraLista);
    }

    Head *segundaLista = copiaLista(lista);

    printf("Segunda Lista\n");
    imprimirLista(segundaLista);
}

Head *copiaLista(Head *lista)
{
    Head *segundaLista = criaLista();

    if (lista->pFirst == NULL)
    {
        printf("LISTA VAZIA!\n");
        return segundaLista;
    }
    else
    {

        Nodo *auxPrimeiraLista = lista->pFirst;

        while (auxPrimeiraLista != NULL)
        {
            inserirFinal(segundaLista, auxPrimeiraLista->info);
            auxPrimeiraLista = auxPrimeiraLista->prox;
        }

        return segundaLista;
    }
}