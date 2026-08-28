/* Implemente uma função int *inserir(int *v, int *n, int valor) que insira um novo elemento no final de um vetor dinâmico. A função deve aumentar o espaço alocado utilizando realloc, atualizar, por meio de n, a quantidade de elementos do vetor e retornar o endereço do vetor após a realocação. */

#include <stdio.h>
#include <stdlib.h>

int *inserir(int *v, int *n, int valor);

int main()
{
    int tamanhoVetor, valorInserido;

    printf("Infome o tamanho do vetor: ");
    scanf("%d", &tamanhoVetor);

    int *v1 = malloc(tamanhoVetor * sizeof(int));

    for (int i = 0; i < tamanhoVetor; i++)
    {
        printf("Informe o valor do primeiro vetor v[%d]: ", i);
        scanf("%d", &v1[i]);
    }

    printf("Informe o valor a ser inserido: ");
    scanf("%d", &valorInserido);

    int *vetorAtualizado = inserir(v1, &tamanhoVetor, valorInserido);

    printf("%p\n", &vetorAtualizado);
    // imprimir ponteiro %p\n, e depois colocar & no ponteiro
}

int *inserir(int *v, int *n, int valor)
{
    v = realloc(v, (*n + 1) * sizeof(int));

    *(v + *n) = valor;

    (*n)++;

    return v;
}