#include <stdlib.h>
#include <stdio.h>

struct No{
    int conteudo;
    struct No * prox;
};

typedef struct No no;

void inserir(int x, no * ini);
no *excluir(no *ini);
void exibir(no * lista);