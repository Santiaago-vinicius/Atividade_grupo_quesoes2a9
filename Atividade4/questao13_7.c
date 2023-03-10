#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de um nó da árvore binária
typedef struct Node {
    int value;
    struct Node* esquerda;
    struct Node* direita;
} Node;

// Função que cria um novo nó com um determinado valor
Node* createNode(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->esquerda = NULL;
    node->direita = NULL;
    return node;
}

// Função que verifica se as duas árvores binárias são iguais
int igual(Node* a, Node* b) {
    // Se ambas as árvores estiverem vazias, elas são iguais
    if (a == NULL && b == NULL) {
        return 1;
    }
    // Se apenas uma das árvores estiver vazia, elas não são iguais
    if (a == NULL || b == NULL) {
        return 0;
    }
    // Verifica se o valor do nó é o mesmo nas duas árvores
    if (a->value != b->value) {
        return 0;
    }
    // Verifica se os filhos do nó são iguais nas duas árvores
    return igual(a->esquerda, b->esquerda) && igual(a->direita, b->direita);
}

int main() {
    // Criando as árvores binárias de exemplo
    Node* A = createNode(1);
    A->esquerda = createNode(2);
    A->direita = createNode(3);
    A->esquerda->esquerda = createNode(4);
    A->esquerda->direita = createNode(5);
    A->esquerda->esquerda = createNode(6);

    Node* B = createNode(1);
    B->esquerda = createNode(2);
    B->direita = createNode(3);
    B->esquerda->esquerda = createNode(4);
    B->esquerda->direita = createNode(5);
    B->direita->esquerda = createNode(6);

    // Verificando se as árvores são iguais
    if (igual(A, B)) {
        printf("As arvores sao iguais.\n");
    } else {
        printf("As arvores nao sao iguais.\n");
    }

    return 0;
}

