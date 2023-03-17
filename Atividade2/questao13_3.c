#include <stdio.h>
#include <stdlib.h>

typedef struct arv {
    int info;
    struct arv *esq;
    struct arv *dir;
} Arv;

Arv *arvore(int valor, Arv *esquerda, Arv *direita) {
    Arv *novo = (Arv *) malloc(sizeof(Arv));
    novo->info = valor;
    novo->esq = esquerda;
    novo->dir = direita;
    return novo;
}

int folhas(Arv *no) {
    // se o nó for NULL, retorna 0
    if (no == NULL) {
        return 0;
    }
    // se o nó não tiver filhos, retorna 1 (é uma folha)
    else if (no->esq == NULL && no->dir == NULL) {
        return 1;
    }
    // caso contrário, soma o número de folhas da subárvore esquerda com o número de folhas
    // da subárvore direita
    else {
        return folhas(no->esq) + folhas(no->dir);
    }
}

int main() {
    // criação de uma árvore binária simples
    Arv *folha1 = arvore(2, NULL, NULL);
    Arv *folha2 = arvore(4, NULL, NULL);
    Arv *no1 = arvore(3, folha1, folha2);
    Arv *folha3 = arvore(6, NULL, NULL);
    Arv *no2 = arvore(7, folha3, NULL);
    Arv *raiz = arvore(5, no1, no2);

    // chamada da função folhas para calcular o número de folhas da árvore
    printf("A arvore tem %d folhas\n", folhas(raiz));

    return 0;
}
