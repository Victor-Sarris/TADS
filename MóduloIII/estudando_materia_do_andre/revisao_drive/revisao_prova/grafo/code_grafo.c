#include <stdio.h>
#include <stdlib.h>

#define TAM 26  // Suporta vértices de 'A' a 'Z'

typedef struct no {
    char vertice;
    struct no *prox;
} No;

typedef struct {
    No *lista[TAM];
} Grafo;

int indice(char c) {
    return c - 'A';
}

Grafo* criarGrafo() {
    Grafo *g = (Grafo *) malloc(sizeof(Grafo));
    for (int i = 0; i < TAM; i++) {
        g->lista[i] = NULL;
    }
    return g;
}

void adicionarAresta(Grafo *g, char origem, char destino) {
    int i = indice(origem);
    int j = indice(destino);

    No *novo1 = (No *) malloc(sizeof(No));
    novo1->vertice = destino;
    novo1->prox = g->lista[i];
    g->lista[i] = novo1;

    No *novo2 = (No *) malloc(sizeof(No));
    novo2->vertice = origem;
    novo2->prox = g->lista[j];
    g->lista[j] = novo2;
}

void removerAresta(Grafo *g, char origem, char destino) {
    int i = indice(origem);
    int j = indice(destino);

    No **atual = &g->lista[i];
    while (*atual != NULL) {
        if ((*atual)->vertice == destino) {
            No *temp = *atual;
            *atual = (*atual)->prox;
            free(temp);
            break;
        }
        atual = &(*atual)->prox;
    }

    atual = &g->lista[j];
    while (*atual != NULL) {
        if ((*atual)->vertice == origem) {
            No *temp = *atual;
            *atual = (*atual)->prox;
            free(temp);
            break;
        }
        atual = &(*atual)->prox;
    }
}

int buscar(Grafo *g, char origem, char destino) {
    int i = indice(origem);
    No *aux = g->lista[i];
    while (aux != NULL) {
        if (aux->vertice == destino)
            return 1;
        aux = aux->prox;
    }
    return 0;
}

void exibirGrafo(Grafo *g) {
    for (int i = 0; i < TAM; i++) {
        if (g->lista[i] != NULL) {
            printf("%c: ", 'A' + i);
            No *aux = g->lista[i];
            while (aux != NULL) {
                printf("%c ", aux->vertice);
                aux = aux->prox;
            }
            printf("\n");
        }
    }
}

int main() {
    Grafo *g = criarGrafo();

    adicionarAresta(g, 'A', 'B');
    adicionarAresta(g, 'A', 'C');
    adicionarAresta(g, 'B', 'D');
    adicionarAresta(g, 'C', 'F');
    adicionarAresta(g, 'D', 'E');
    adicionarAresta(g, 'E', 'F');

    printf("Grafo:\n");
    exibirGrafo(g);

    printf("\nBuscar aresta A-B: %d", buscar(g, 'A', 'B'));
    printf("\nBuscar aresta B-F: %d", buscar(g, 'B', 'F'));

    removerAresta(g, 'A', 'B');
    printf("\n\nApós remover aresta A-B:\n");
    exibirGrafo(g);

    return 0;
}
