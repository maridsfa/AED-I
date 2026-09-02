/* Considere a struct Produto do exercício anterior. Implemente uma função Produto **criar_estoque_ptrs(int n) que aloque dinamicamente um vetor de n ponteiros para Produto e, para cada posição, aloque um Produto, preenchendo seus campos com dados lidos do usuário. Implemente também void
liberar_estoque_ptrs(Produto **estoque, int n), que deve liberar cada Produto e, em seguida, o vetor de ponteiros.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    float preco;
    int quantidade;
} Produto;

Produto **criar_estoque_ptrs(int n);
void liberar_estoque_ptrs(Produto **estoque, int n);

int main()
{
    int tamanho;

    printf("Informe o tamanho do ponteiro: ");
    scanf("%d", &tamanho);

    Produto **estoque = criar_estoque_ptrs(tamanho);

    void liberar_estoque_ptrs(estoque, tamanho);
}

Produto **criar_estoque_ptrs(int n)
{
    Produto **estoque;
    // é uma variável que armazena o endereço de outra variável que também armazena um endereço, que seria o endereço para o primeiro ponteiro que o malloc deu

    estoque = malloc(n * sizeof(Produto *));

    for (int i = 0; i < n; i++)
    {
        estoque[i] = malloc(sizeof(Produto));

        printf("\nProduto %d\n", i + 1);

        printf("Nome: ");
        scanf(" %49[^\n]", estoque[i]->nome);

        printf("Preco: ");
        scanf("%f", &estoque[i]->preco);

        printf("Quantidade: ");
        scanf("%d", &estoque[i]->quantidade);
    }

    return estoque;
}

void liberar_estoque_ptrs(Produto **estoque, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(estoque[i]);
    }

    free(estoque);
}