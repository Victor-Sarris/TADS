#include <stdlib.h>
#include <stdio.h>
#include "teste.h"

Arv * inserir(char c, Arv * sae, Arv * sad){
    Arv * nova = malloc(sizeof(Arv));
    nova->cont = c;
    nova->esq = sae;
    nova->dir = sad;
    return nova;
}



void exibir(Arv * a){
    if(a!=NULL){
        printf("<%c", a->cont);
        exibir(a->esq);
        exibir(a->dir);
        printf(">");
    } else {
        printf("<>");
    }
}

Arv * criar(char c, Arv *sae, Arv *sad) {
    return inserir(c, sae, sad);
}

int main(){ /*
    Arv *a1 = inserir('d', NULL, NULL);
    Arv *a2 = inserir('b', NULL, a1);
    Arv *a3 = inserir('e', NULL, NULL);
    Arv *a4 = inserir('f', NULL, NULL);
    Arv *a5 = inserir('c', a3, a4);
    Arv *a6 = inserir('a', a2, a5);
    */
   Arv * a = criar('a', criar('b', criar('x', criar('y', NULL, NULL), criar('z', NULL, NULL)), criar('d', NULL, NULL)), criar('c', criar('e', NULL, NULL), criar('f', NULL, NULL)));

    printf("Exibindo a árvore\n");
    /*exibir(a6);*/
    exibir(a);

    return 0;
}