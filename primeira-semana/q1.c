#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    float valor;
    int quantidade;
} Produto;

void menu(int *opcao);
void cadastrarProduto(Produto *produto);
void exibirRelatorio(Produto *produto);

int main() {
    Produto *estoque = NULL;
    int totalProdutos = 0;
    int opcao;

    do {
        menu(&opcao);

        switch (opcao) {
            case 1: {
                if (estoque == NULL) {
                    estoque = (Produto *) malloc(sizeof(Produto));
                } else {
                    estoque = (Produto *) realloc(estoque, (totalProdutos + 1) * sizeof(Produto));
                }

                if (estoque == NULL) {
                    printf("Erro ao alocar memoria!\n");
                    return 1;
                }
                cadastrarProduto(&estoque[totalProdutos]);
                totalProdutos++;
                break;
            }
            case 2: {
                printf("\n===== RELATORIO DO ESTOQUE =====\n");
                for (int i = 0; i < totalProdutos; i++) {
                    exibirRelatorio(&estoque[i]);
                }
                printf("\n");
                break;
            }
            case 0: {
                free(estoque);
                printf("Encerrando o programa...\n");
                break;
            }
            default: {
                printf("Opcao invalida!\n");
                break;
            }
        }

    } while (opcao != 0);

    return 0;
}

void menu(int *opcao) {
    printf("\n###### CONTROLE DE ESTOQUE ######\n");
    printf("1 - Adicionar produto\n");
    printf("2 - Listar produtos\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
    scanf("%d", opcao);
}

void cadastrarProduto(Produto *produto) {
    printf("\n###### Cadastro de Produto ######\n");

    printf("Nome: ");
    scanf(" %99[^\n]", produto->nome);

    printf("Valor: ");
    scanf("%f", &produto->valor);

    printf("Quantidade: ");
    scanf("%d", &produto->quantidade);
}

void exibirRelatorio(Produto *produto) {
    float valorTotal = produto->valor * produto->quantidade;
    printf("Nome: %s; Valor: R$ %.2f; Quantidade: %d; Valor Total: R$ %.2f\n",
           produto->nome, produto->valor, produto->quantidade, valorTotal);
}