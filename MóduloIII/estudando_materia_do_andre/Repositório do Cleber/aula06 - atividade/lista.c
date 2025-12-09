#include <stdio.h>
#include <stdlib.h>

struct no
{
    int conteudo;
    struct no *proximo;
};
typedef struct no No;

void inserirFim(No **cabeca, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    novo->conteudo = valor;
    novo->proximo = NULL;

    if (*cabeca == NULL) {
        *cabeca = novo;
    } else {
        No *atual = *cabeca;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

void imprime(No *cabeca) {
    No *atual = cabeca;
    int i = 0;
    while (atual != NULL) {
        i++;
        printf("Elemento %d da lista: %3d\n", i, atual->conteudo);
        atual = atual->proximo;
    }
    printf("Quantidade total de elementos: %d\n", i);
}

void liberaInicio(No **cabeca) {
    if (*cabeca == NULL) {
        printf("Lista já está vazia!\n");
        return;
    }

    No *temp = *cabeca;
    printf("Elemento Removido: %d\n", temp->conteudo);
    *cabeca = temp->proximo;
    free(temp);
}

int main() {
    No *cabeca = NULL; // Lista inicialmente vazia

    inserirFim(&cabeca, 10);
    inserirFim(&cabeca, 20);
    inserirFim(&cabeca, 30);

    printf("Lista após inserções:\n");
    imprime(cabeca);

    liberaInicio(&cabeca); // Remove o 10
    printf("\nLista após remover o primeiro elemento:\n");
    imprime(cabeca);

    liberaInicio(&cabeca); // Remove o 20
    liberaInicio(&cabeca); // Remove o 30
    liberaInicio(&cabeca); // Lista vazia agora

    printf("\nLista final:\n");
    imprime(cabeca);

    return 0;
}
