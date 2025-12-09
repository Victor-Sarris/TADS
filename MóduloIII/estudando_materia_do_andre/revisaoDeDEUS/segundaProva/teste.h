#include <stdlib.h>
#include <stdio.h>

struct Arv{
    char conteudo;
    struct Arv *esq; 
    struct Arv *dir;
};

typedef struct Arv arv;

arv *inserir(char c, arv *sae, arv *sad);
void exibir(arv * a);
arv *buscar(char c, arv * a);
