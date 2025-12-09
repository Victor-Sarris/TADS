#include <stdlib.h>
#include <stdio.h>

typedef struct grafo_horizontal
{
    int conteudo;
    struct grafo_horizontal *prox;
} Grafo_H;

struct grafo_vertical
{
    int conteudo;
    Grafo_H *adj;
    struct grafo_vertical *prox;
} grafo_vertical;
typedef struct grafo_vertical Grafo_V;

Grafo_H* criarAresta(Grafo_H *p, int c){
    Grafo_H *novo = (Grafo_H*) malloc(sizeof(Grafo_H));
    novo->conteudo = c;
    novo->prox = p;
    return novo;
}

Grafo_V* criarVertice(Grafo_V *g, Grafo_H *h, int c){
    Grafo_V *novo = (Grafo_V*) malloc(sizeof(Grafo_V));
    novo->conteudo = c;
    novo->adj = h;
    novo->prox =g;
    return novo;
}

void addAresta(Grafo_V *g, int origem, int destino){
    Grafo_V *p = g;
    while(p != NULL && p->conteudo != origem){
        p = p->prox;
    }
    Grafo_H *l = p->adj;
    p->adj = criarAresta(l, destino);
}

void percorrerListaAdj(Grafo_V *g){
    while (g!=NULL)
    {
        printf("\n>Entrando no Vertice %d:\n",g->conteudo);
        while (g->adj != NULL)
        {
            printf(">>>De %d na aresta %d;\n", g->conteudo, g->adj->conteudo);
            g->adj = g->adj->prox;;
        }
        g = g->prox;
    }    
}

int main(){
    Grafo_V *g = NULL;

    g = criarVertice(g, NULL, 1);
    g = criarVertice(g, NULL, 2);
    g = criarVertice(g, NULL, 3);

    addAresta(g, 1, 4);

    addAresta(g, 2, 1);
    addAresta(g, 2, 3);

    addAresta(g, 3, 1);
    addAresta(g, 3, 2);

    percorrerListaAdj(g);
    return 0;
}