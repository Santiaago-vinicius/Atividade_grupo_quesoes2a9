#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct arv {
	char info;
    struct arv *esq;
	struct arv *dir;
}Arv;


Arv *arvore(char x,Arv *e,Arv *d){
	Arv *novo=(Arv *)malloc(sizeof(Arv));
	novo->esq=e;
	novo->dir=d;
	novo->info=x;
	return novo;

}

void imprime(Arv *n){

			if (n!=NULL){

				cout<<"<"<<n->info;
				imprime(n->esq);
				imprime(n->dir);
				cout<<">";
			   }
			   else
			     cout<<"<>";
			}

int calculaQuantNos(Arv *no){

		}

int calculaQuantNosFolha(Arv *no){

		}



int alturaArvore(Arv *no){


		}

int procura(Arv *no, char valor){

		}

void removeSubArvore(Arv **raiz, char valor) {
    if (*raiz == NULL) {
        return;
    }

    if ((*raiz)->info > valor) {
        removeSubArvore(&((*raiz)->esq), valor);
    } else if ((*raiz)->info < valor) {
        removeSubArvore(&((*raiz)->dir), valor);
    } else {
        // encontrou o nó a ser removido
        Arv *aux;

        if ((*raiz)->esq == NULL) {
            // nó tem apenas filho direito ou nenhum filho
            aux = *raiz;
            *raiz = (*raiz)->dir;
            free(aux);
        } else if ((*raiz)->dir == NULL) {
            // nó tem apenas filho esquerdo
            aux = *raiz;
            *raiz = (*raiz)->esq;
            free(aux);
        } else {
            // nó tem dois filhos
            aux = (*raiz)->dir;

            while (aux->esq != NULL) {
                aux = aux->esq;
            }

            (*raiz)->info = aux->info;
            removeSubArvore(&((*raiz)->dir), aux->info);
        }
    }
}

int main() {

 Arv *c = arvore('c',NULL,NULL);
 Arv *z = arvore('z',0,0);
 Arv *o = arvore('o',0,0);

 // monta a árvore
 c->esq = z;
 c->dir = o;

 // imprime a árvore
 imprime(c);
 cout << endl;

 // remove o nó 'z'
 removeSubArvore(&c, 'z');

 // imprime a árvore após a remoção
 imprime(c);
 cout << endl;

 return 0;
}
