#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[50];
    float nota;
    int idade;
} Aluno;

void free_alunos(Aluno *aluno);
int inserir_aluno(Aluno **alunos, int *n, Aluno novo);
int remover_aluno(Aluno **alunos, int *n, int posicao);
void listar_alunos(Aluno *aluno, int n);

int main()
{
    int op, n = 0;
    Aluno *alunos = NULL;

    do
    {

        printf("-- MENU --\n");
        printf("1. Cadastrar aluno\n");
        printf("2. Remover aluno pela posição\n");
        printf("3. Listar todos os alunos\n");
        printf("0. Encerrar\n");

        scanf("%d", &op);

        if (op == 0)
        {
            free_alunos(alunos);
            break;
        }

        if (op == 1)
        {
            Aluno alunoNovo;
            int flagInsertion = inserir_aluno(&alunos, &n, alunoNovo);

            if (flagInsertion)
            {
                printf("Aluno alocado com sucesso!\n");
            }
            else
            {
                printf("Erro ao alocar aluno!\n");
            }
        }

        if (op == 2)
        {
            int posicao;
            printf("Informe a posicao que deseja excluir: ");
            scanf("%d", &posicao);

            int flagDelete = remover_aluno(&alunos, &n, posicao);

            if (flagDelete)
            {
                printf("Aluno removido com sucesso!\n");
            }
            else
            {
                printf("Erro ao remover aluno!\n");
            }
        }

        if (op == 3)
        {
            listar_alunos(alunos, n);
        }
    } while (op != 0);

    printf("Cadastro finalizado!");
}

int inserir_aluno(Aluno **alunos, int *n, Aluno novo)
{

    if (*n == 0)
    {
        *alunos = (Aluno *)malloc(sizeof(Aluno));
    }
    else
    {
        *alunos = (Aluno *)realloc(*alunos, (*n + 1) * sizeof(Aluno));
    }

    if (*alunos == NULL)
    {
        return 0;
    }

    printf("Nome: ");
    scanf(" %49[^\n]", &novo.nome);

    printf("Nota: ");
    scanf("%f", &novo.nota);

    printf("Idade: ");
    scanf("%d", &novo.idade);

    *(*alunos + *n) = novo;

    (*n)++;

    return 1;
}

int remover_aluno(Aluno **alunos, int *n, int posicao)
{
    if (posicao < 0 || posicao >= *n)
    {
        return 0;
    }

    if (*n == 1)
    {
        free(*alunos);
        *alunos = NULL;
        *n = 0;
        return 1;
    }

    for (int c = posicao; c < *n - 1; c++)
    {
        *(*alunos + c) = *(*alunos + (c + 1));
    }

    Aluno *aux = realloc(*alunos, (*n - 1) * sizeof(Aluno));

    if (aux == NULL)
    {
        return 0;
    }

    (*n)--;

    *alunos = aux;
    return 1;
}

void listar_alunos(Aluno *alunos, int n)
{
    for (int c = 0; c < n; c++)
    {
        printf("Nome: %s\n", alunos[c].nome);
        printf("Nota: %.2f\n", alunos[c].nota);
        printf("Idade: %d\n", alunos[c].idade);
    }
}

void free_alunos(Aluno *aluno)
{
    free(aluno);
}