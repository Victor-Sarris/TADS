#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

void inserir(int x, no *ini){
    no *novo = malloc(sizeof(no));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }

    novo->conteudo = x;
    novo->prox = ini->prox;
    ini->prox = novo;
}

no *excluir(no *ini){
    no *morta;

    if (ini->prox != NULL) {
        morta = ini->prox;
        ini->prox = morta->prox;
        free(morta);
    }

    return ini;
}

void exibir(no *lista){
    no *p;
    for(p = lista->prox; p != NULL; p = p->prox){
        printf("elemento encontrado: %d\n", p->conteudo);
    }
}

int main(){
    no *lista = malloc(sizeof(no));
    if (lista == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }
    lista->prox = NULL;

    inserir(3, lista);
    inserir(5, lista);
    inserir(7, lista);

    exibir(lista);

    lista = excluir(lista); // remove o primeiro elemento (7)

    printf("Depois da exclusão:\n");
    exibir(lista);

    return 0;
}
