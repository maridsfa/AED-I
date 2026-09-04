#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    float preco;
    int quantidade;
} Produto;

int inserir_produto(Produto **estoque, int *n, Produto novo);
int excluir_produto(Produto **estoque, int *n, int posicao);
void exibir_estoque(Produto *estoque, int n);
void liberar_estoque_ptrs(Produto **estoque, int n);

int main()
{
    int op, n = 0;

    Produto *estoque = NULL;

    do
    {
        printf("-- MENU --\n");
        printf("1. Adicionar produto\n");
        printf("2. Excluir produto\n");
        printf("3. Exibir estoque\n");
        printf("0. Sair\n");
        scanf("%d", &op);

        if (op == 0)
        {
            liberar_estoque_ptrs(&estoque, n);
            break;
        }
        if (op == 1)
        {
            Produto novo;
            int flagInsertion = inserir_produto(&estoque, &n, novo);

            if (flagInsertion == 0)
            {
                printf("Erro ao alocar memoria!\n");
            }
            else
            {
                printf("Produto alocacado com sucesso!");
            }
        }

        if (op == 2)
        {
            int posicaoVetorDelete;
            printf("Informa a posicao do Produto que deseja deletar: ");
            scanf("%d", &posicaoVetorDelete);
            int flagDelete = excluir_produto(&estoque, &n, posicaoVetorDelete);

            if (flagDelete == 0)
            {
                printf("Erro ao deletar produto!\n");
            }
            else
            {
                printf("Produto deletado com sucesso!\n");
            }
        }

        if (op == 3)
        {
            exibir_estoque(estoque, n);
        }
    } while (op != 0);

    printf("Programa encerrado!");
}

int inserir_produto(Produto **estoque, int *n, Produto novo)
{
    if (*n == 0)
    {
        *estoque = (Produto *)malloc((*n + 1) * sizeof(Produto));
    }
    else
    {
        *estoque = realloc(*estoque, (*n + 1) * sizeof(Produto));
    }

    if (*estoque == NULL)
    {
        return 0;
    }

    printf("Nome: ");
    scanf(" %49[^\n]", &novo.nome);

    printf("Preco: ");
    scanf("%f", &novo.preco);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    (*estoque)[*n] = novo;

    (*n)++;
    return 1;
}

int excluir_produto(Produto **estoque, int *n, int posicao)
{
    if (*n == 0)
    {
        free(*estoque);
        *estoque = NULL;
        return 1;
    }

    if (posicao < 0 || posicao >= *n)
    {
        return 0;
    }

    for (int c = posicao; c < *n - 1; c++)
    {
        (*estoque)[c] = (*estoque)[c + 1];
    }

    *estoque = realloc(*estoque, (*n - 1) * sizeof(Produto));

    if (estoque == NULL)
    {
        return 0;
    }

    (*n)--;

    return 1;
}

void exibir_estoque(Produto *estoque, int n)
{
    for (int c = 0; c < n; c++)
    {
        printf("Nome: %s\n", estoque[c].nome);
        printf("Valor: %.2f\n", estoque[c].preco);
        printf("Quantidade: %d\n", estoque[c].quantidade);
        printf("Total: %.2f\n", estoque[c].preco * estoque[c].quantidade);
    }
}

void liberar_estoque_ptrs(Produto **estoque, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(estoque[i]);
    }

    free(estoque);
}