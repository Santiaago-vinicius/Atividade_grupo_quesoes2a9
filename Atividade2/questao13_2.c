#include<stdio.h>
#include<stdlib.h>

// definição da estrutura de nó de uma árvore binária
typedef struct arv {
    int info;
    struct arv *esq;
    struct arv *dir;
} Arv;

// função para criar um novo nó da árvore
Arv *arvore(int valor, Arv *esquerda, Arv *direita) {
    Arv *novo = (Arv *) malloc(sizeof(Arv));
    novo->info = valor;
    novo->esq = esquerda;
    novo->dir = direita;
    return novo;
}

// função para calcular o número de nós em uma árvore
int nos(Arv *no) {
    // se o nó for NULL, retorna 0
    if (no == NULL) {
        return 0;
    } else {
        // caso contrário, soma 1 (para contar o próprio nó)
        // com o número de nós na subárvore esquerda e
        // com o número de nós na subárvore direita
        return 1 + nos(no->esq) + nos(no->dir);
    }
}

// função principal do programa
int main() {
    // criação de uma árvore binária simples
    Arv *folha1 = arvore(2, NULL, NULL);
    Arv *folha2 = arvore(4, NULL, NULL);
    Arv *no1 = arvore(3, folha1, folha2);
    Arv *folha3 = arvore(6, NULL, NULL);
    Arv *folha4 = arvore(8, NULL, NULL);
    Arv *no2 = arvore(7, folha3, folha4);
    Arv *raiz = arvore(5, no1, no2);

    // chamada da função nos para calcular o número de nós da árvore
    printf("A arvore tem %d nos\n", nos(raiz));
    return 0;
}
