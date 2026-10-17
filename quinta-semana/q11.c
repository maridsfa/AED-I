#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void removeNumerosPares(Head *lista);

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

    printf("\n--- ANTES DA REMOCAO ---");
    imprimeLista(lista);

    removeNumerosPares(lista);

    printf("\n--- APOS REMOVER OS PARES ---");
    imprimeLista(lista);

    return 0;
}

void removeNumerosPares(Head *lista)
{
    Nodo *atual = lista->pFirst;
    Nodo *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->info.cod % 2 == 0)
        {
            Nodo *remover = atual;

            if (anterior == NULL)
            {
                lista->pFirst = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
            }

            atual = atual->prox;
            free(remover);
        }
        else
        {
            anterior = atual;
            atual = atual->prox;
        }
    }
}
