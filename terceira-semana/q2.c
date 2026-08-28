/* Considere a seguinte struct:

    typedef struct {
        char nome[50];
        float preco;
    int quantidade;
    } Produto;

Implemente uma função Produto *criar_estoque(int n) que aloque dinamicamente um
vetor de n Produto e, percorrendo-o por meio de um ponteiro, leia os dados de cada
produto. A função deve retornar o endereço do vetor alocado. */

#include <stdio.h>
#include <stdlib.h>

// Alocar e percorrer (pelo vetor)

typedef struct
{
    char nome[50];
    float preco;
    int quantidade;
} Produto;

Produto *criar_estoque(int n);

int main()
{
    int tamanhoVetor;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanhoVetor);

    Produto *produtoMain = criar_estoque(tamanhoVetor);
    Produto *produtoAux = produtoMain;

    for (int c = 0; c < tamanhoVetor; c++)
    {
        printf("####################\n");
        printf("Nome: %s\n", produtoAux->nome);

        printf("Preco: %.2f\n", produtoAux->preco);

        printf("Quantidade: %d\n", produtoAux->quantidade);

        produtoAux++;
    }

    free(produtoMain);
}

Produto *criar_estoque(int n)
{
    Produto *vetorProduto = (Produto *)malloc(n * sizeof(Produto));
    Produto *p = vetorProduto;
    // vetorProduto e p apontam para o mesmo endereço.

    for (int c = 0; c < n; c++)
    {
        printf("Nome: ");
        scanf(" %49[^\n]", p->nome);

        printf("Preco: ");
        scanf("%f", &p->preco);

        printf("Quantidade: ");
        scanf("%d", &p->quantidade);

        p++;
    }

    return vetorProduto;
}