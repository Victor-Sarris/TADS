#include <stdlib.h>
#include <stdio.h>
struct no{
    char conteudo;
    struct no *sae;
    struct no *sad;
} no;
typedef struct no Arv;

void exibir(Arv *a){
    if(a!=NULL){
        printf("<%c", a->conteudo);
        exibir(a->sae);
        exibir(a->sad);
        printf(">");
    }else{
        printf("<>");
    }
}
Arv * criar(char *c, Arv *e, Arv *d){
    Arv *arv = (Arv*) malloc(sizeof(Arv));
    arv->conteudo = c;
    arv->sae = e;
    arv->sad = d;
    return arv;
}

int main() {
    // Criando nós folha
    Arv *d = criar('D', NULL, NULL);
    Arv *e = criar('E', NULL, NULL);
    Arv *f = criar('F', NULL, NULL);

    // Criando nós intermediários
    Arv *b = criar('B', NULL, d);
    Arv *c = criar('C', e, f);

    // Criando raiz
    Arv *raiz = criar('A', b, c);

    // Exibindo a árvore
    printf("Arvore: ");
    exibir(raiz);
    printf("\n");
    return 0;
}
