#include <stdio.h>
#include <stdlib.h>
#include "teste.h"

arv *inserir(char c, arv *sae, arv *sad){
    arv * a;
    a = malloc(sizeof(arv));
    a->conteudo = c;
    a->esq = sae;
    a->dir = sad;

    return a;
}

void exibir(arv * a){
    if(a !=NULL){
        printf("<%c", a->conteudo);
        exibir(a->esq);
        exibir(a->dir);
        printf(">");
    } else{
        printf("<>");
    }
}

arv *buscar(char c, arv * a){
    if(a==NULL){
        return 0;
    } else{
        return a->conteudo == c || buscar(c, a->esq) || buscar(c, a->dir);
    }
}

int main(){
    arv *arvore = inserir('a', inserir('d', NULL, NULL), inserir('b', NULL, inserir('f', inserir('g', NULL, NULL), inserir('j', NULL, NULL))));
    printf("\n exibindo a arvore: \n");
    exibir(arvore);
}