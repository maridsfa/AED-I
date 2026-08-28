/* Considere a seguinte struct:

    typedef struct {
        int x;
        int y;
    } Ponto;

Implemente uma função Ponto *criar_ponto(int x, int y) que aloque dinamicamente um Ponto, atribua os valores aos seus campos e retorne o ponteiro criado. Implemente também void destruir_ponto(Ponto *p), que deve liberar a memória alocada.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Ponto;

Ponto *criar_ponto(int x, int y);
void destruir_ponto(Ponto *p);

int main()
{
    Ponto *ponto;
    int x, y;

    printf("Informe o valor para x: ");
    scanf("%d", &x);

    printf("Informe o valor para y: ");
    scanf("%d", &y);

    ponto = criar_ponto(x, y);

    printf("Ponto x: %d\n", ponto->x);
    printf("Ponto y: %d\n", ponto->y);

    destruir_ponto(ponto);
}

Ponto *criar_ponto(int x, int y)
{
    Ponto *pontoFuncao;

    pontoFuncao = (Ponto *)malloc(sizeof(Ponto));
    pontoFuncao->x = x;
    pontoFuncao->y = y;

    return pontoFuncao;
}

void destruir_ponto(Ponto *p)
{
    free(p);
}