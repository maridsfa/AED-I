#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Nodo *criaNo(Dados *dado);
int retornaQuantidadeElementos(Head *lista);

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

    int quantidadeElementos = retornaQuantidadeElementos(lista);
    printf("Quantidade de elementos: %d\n", quantidadeElementos);

    liberaLista(lista);
    free(lista);
}

//implementar função
int retornaQuantidadeElementos(Head *lista)
{
}