#include <stdio.h>
#include <stdlib.h>

struct arv
{
    char info;
    struct arv *esq;
    struct arv *dir;
};

typedef struct arv Arv;

Arv *criaArvore(char c, Arv *esquerda, Arv *direita);
int contaNos(Arv *raiz);

int main()
{
    Arv *noB = criaArvore('B', NULL, NULL);
    Arv *noC = criaArvore('C', NULL, NULL);

    Arv *raiz = criaArvore('A', noB, noC);

    int totalNos = contaNos(raiz);

    printf ("Total de nos: %d", totalNos);
}

Arv *criaArvore(char c, Arv *esquerda, Arv *direita)
{
    Arv *p = (Arv *)malloc(sizeof(Arv));

    p->info = c;
    p->esq = esquerda;
    p->dir = direita;

    return p;
}

int contaNos(Arv *raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }

    int nosEsquerda = contaNos(raiz->esq);
    int nosDireita = contaNos(raiz->dir);

    return 1 + nosDireita + nosEsquerda;
}