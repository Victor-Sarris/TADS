#include <stdio.h>
#include <stdlib.h>
#include "cabecalho.h"

arv * inserir(char c, arv *sae, arv *sad){
    arv * nova;
    nova = malloc(sizeof(arv));
    nova->conteudo = c;
    nova->esq = sae;
    nova->dir = sad;
    return nova;
}


void exibir(arv * arvore){
    if(arvore != NULL){
        printf("<%c", arvore->conteudo);
        exibir(arvore->esq);
        exibir(arvore->dir);
        printf(">");
    } else{
        printf("<>");
    }
}

int buscar(char c, arv *arvore){ //buscar o elemento dentro de uma arvore
    if(arvore == NULL){
        return 0;
    } else{
        return (arvore->conteudo == c) || buscar(c, arvore->esq) || buscar(c, arvore->dir);
    }
    
}

int main(){

    arv * a = inserir('a',inserir('b', inserir('x', inserir('y', NULL, NULL), inserir('z', NULL, NULL)), inserir('d', NULL, NULL)), inserir('c', inserir('e', NULL, NULL), inserir('f', NULL, NULL)));

    exibir(a);

    return 0;
}