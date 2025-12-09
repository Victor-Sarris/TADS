#include <stdlib.h>
#include <stdio.h>

struct Celula{
    int conteudo;
    struct Celula *prox;
};

typedef struct Celula celula;

// criado o metodo de inserir
void inserir(int x, celula *ini){
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->conteudo = x;
    nova->prox = ini->prox; // ini->prox também vai ser NULL
    ini->prox = nova;
}

// criando metodo de exibir
void exibir(celula *ini){
    celula *p;
    for(ini->prox; p!=NULL; p = p->prox){
        printf("%d\n", p->conteudo);
    }
}

// criando funcao de excluir elemento da lista
void excluir(celula *ini){
    celula *morta = ini;
    ini = morta->prox;
    free(morta);
    return ini;
}