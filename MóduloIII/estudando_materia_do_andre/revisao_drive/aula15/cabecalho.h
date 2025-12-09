#include <stdio.h>
#include <stdlib.h>

struct arv{
    char cont;
    struct arv *esq;
    struct arv *dir;
};

typedef struct arv Arv;

Arv * inserir(char c, Arv * sae, Arv * sad);
Arv * criar(char c, Arv * sae, Arv * sad);
void exibir(Arv * a);
