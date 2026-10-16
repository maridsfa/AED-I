#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void inverteLista(Head *lista);

int main()
{
    Head *lista = criaLista();
    Dados temporario;
    char continuar = 's';

    while (continuar == 's' || continuar == 'S')
    {
        printf("Codigo: ");
        scanf("%d", &temporario.cod);

        printf("Nome: ");
        scanf("%s", &temporario.nome);

        printf("Preco: ");
        scanf("%f", &temporario.preco);

        inserirFinal(lista, temporario);

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &continuar);
    }

    inverteLista(lista);
    printf("\nLista atualizada:\n");
    imprimirLista(lista);

    liberaLista(lista);
}

void inverteLista(Head *lista)
{
    if (listaVazia(lista))
    {
        printf("LISTA VAZIA\n");
        return;
    }

    Nodo *anterior = NULL;
    Nodo *atual = lista->pFirst;
    Nodo *proximo = NULL;

    while (atual != NULL)
    {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    lista->pFirst = anterior;
}
