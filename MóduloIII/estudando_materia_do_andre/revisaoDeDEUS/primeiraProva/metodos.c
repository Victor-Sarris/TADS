#include <stdlib.h>
#include "listaE.h"

void inserir(int x, Celula *ini){
    Celula *nova;
    nova = malloc(sizeof(Celula));
    nova->conteudo = x;
    nova->proximo = ini->proximo;
    ini->proximo = nova;
};

