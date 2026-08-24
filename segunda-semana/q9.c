/* Implemente uma função int *copia_vetor(int *v, int n) que receba um
vetor de inteiros e seu tamanho, aloque dinamicamente um novo vetor e copie para ele
todos os elementos do vetor original, sem alterar o vetor original. A função deve retornar
o endereço do novo vetor. */

#include <stdio.h>
#include <stdlib.h>

int *copia_vetor(int *v, int n);

int main()
{
    int tamanhoVetor;

    printf("Infome o tamanho do vetor: ");
    scanf("%d", &tamanhoVetor);

    int v[tamanhoVetor];

    for (int i = 0; i < tamanhoVetor; i++)
    {
        printf("Informe o valor do vetor v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    int *novoVetorAlocado = copia_vetor(v, tamanhoVetor);

    printf("Vetor original:\n");

    for (int i = 0; i < tamanhoVetor; i++)
    {
        printf("%d\n", v[i]);
    }

    printf("Vetor copiado:\n");

    for (int i = 0; i < tamanhoVetor; i++)
    {
        printf("%d\n", novoVetorAlocado[i]);
    }

    free(novoVetorAlocado);
}

/* int *copia_vetor(int *v, int n)
{
    int novoVetor[n]; /

    for (int i = 0; i < n; i++)
    {
        novoVetor[i] = *(v + i);
    }

    return novoVetor;

    não tem como retornar o novoVetor, ele é alocado até o fim da função em tempo de execução, depois que a função termina, deixa de existir, então não tem como retornar endereço.

    precisa usar o malloc - pede ao sistema operacional/runtime um espaço de memória dinâmico, que fica disponível até liberar explicitamente essa memória com free, não dependa do final da função.

} */

int *copia_vetor(int *v, int n)
{
    int *novoVetor = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        novoVetor[i] = v[i];
    }

    return novoVetor;
}