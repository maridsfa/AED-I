
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void removeElemento(Head *lista, int num);

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
        scanf("%s", temporario.nome);

        printf("Preco: ");
        scanf("%f", &temporario.preco);

        inserirFinal(lista, temporario);

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &continuar);
    }

    int valorExclusao;

    printf("Informe o codigo para exclusao: ");
    scanf("%d", &valorExclusao);

    removeElemento(lista, valorExclusao);

    printf("\nLista atualizada:\n");
    imprimirLista(lista);

    liberaLista(lista);
    free(lista);

    return 0;
}

void removeElemento(Head *lista, int num)
{
    if (listaVazia(lista))
    {
        printf("LISTA VAZIA\n");
        return;
    }

    Nodo *anterior = NULL;
    Nodo *atual = lista->pFirst;

    while (atual != NULL)
    {
        if (atual->info.cod == num)
        {
            if (anterior == NULL)
            {
                lista->pFirst = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
            }

            free(atual);

            printf("Elemento removido com sucesso!\n");
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }

    printf("Codigo nao encontrado!\n");
}
