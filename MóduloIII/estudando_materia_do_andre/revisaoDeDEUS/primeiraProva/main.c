#include <stdlib.h>
#include <stdio.h>
#include "listaE.h"

int main(){
    Celula *lista;
    lista = malloc(sizeof(Celula));
    lista->proximo = NULL;
    inserir(3, lista);
}