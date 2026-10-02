#include <stdio.h>
#include <stdlib.h>

struct arv
{
    int info;
    struct arv *esq;
    struct arv *dir;
};

typedef struct arv Arv;

Arv *criaArvore(int info, Arv *esquerda, Arv *direita);
int somaNos(Arv *raiz);

int main()
{
    Arv *no2 = criaArvore(2, NULL, NULL);
    Arv *no3 = criaArvore(3, NULL, NULL);

    Arv *raiz = criaArvore(1, no2, no3);

    int valorNos = somaNos(raiz);

    printf("Soma dos nos: %d\n", valorNos);

    return 0;
}

Arv *criaArvore(int info, Arv *esquerda, Arv *direita)
{
    Arv *p = (Arv *)malloc(sizeof(Arv));

    p->info = info;
    p->esq = esquerda;
    p->dir = direita;

    return p;
}

int somaNos(Arv *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }

    return raiz->info + somaNos(raiz->esq) + somaNos(raiz->dir);
}