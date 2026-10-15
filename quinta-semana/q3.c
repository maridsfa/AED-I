#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int quantidadeNumeroComparacao(Head *lista, int comp);

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

    int valorComparacao;
    printf("Informe o valor para comparacao: ");
    scanf("%d", &valorComparacao);

    int quantidadeValorComparacao = quantidadeNumeroComparacao(lista, valorComparacao);

    printf("Quantidade de valores que o de referencia: %d", quantidadeValorComparacao);

    liberaLista(lista);
    free(lista);
}

int quantidadeNumeroComparacao(Head *lista, int comp)
{
    int cont = 0;
    if (listaVazia(lista))
    {
        return cont;
    }

    Nodo *atual = lista->pFirst;

    while (atual != NULL)
    {
        if (atual->info.cod > comp)
        {
            cont++;
        }
        atual = atual->prox;
    }

    return cont;
}