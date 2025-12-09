#include <stdlib.h>
#include "listaE.h"

struct celula{
    int conteudo;
    struct celula *proximo; 
};

typedef struct celula Celula;


void inserir(int x, Celula *ini);
void exibir(Celula *ini);

void inserir(int x, Celula *ini){
    Celula *nova;
    nova = malloc(sizeof(Celula));
    nova->conteudo = x;
    nova->proximo = ini->proximo;
    ini->proximo = nova;
};

int main(){
    Celula *lista;
    lista = malloc(sizeof(Celula));
    lista->proximo = NULL;
    inserir(3, lista);
};
