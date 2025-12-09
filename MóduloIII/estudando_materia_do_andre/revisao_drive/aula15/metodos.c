#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"

Arv * inserir(char c, Arv * sae, Arv * sad){
    Arv * novo = (Arv *) malloc(sizeof(Arv));
    novo->cont = c;
    novo->esq = sae;
    novo->dir = sad;
    return novo;
}

void exibir(Arv * arvore){
    if(arvore != NULL){
        printf("<%c", arvore->cont);
        exibir(arvore->esq);
        exibir(arvore->dir);
        printf(">");
    } else{
        printf("<>");
    }
}

int pertence(Arv * arvore, char c){
    if(arvore == NULL){
        return 0;
    } else{
        return (arvore->cont == c) || pertence(arvore->esq, c) || pertence(arvore->dir, c);
    }
}

Arv * criar(char c, Arv * sae, Arv * sad){
    return inserir(c, sae, sad);
}

int main(){

    Arv * a = inserir('a',inserir('b', inserir('x', inserir('y', NULL, NULL), inserir('z', NULL, NULL)), inserir('d', NULL, NULL)), inserir('c', inserir('e', NULL, NULL), inserir('f', NULL, NULL)));

    exibir(a);

    return 0;
}
