#include <stdlib.h>
#include "listaE.h"
#include <stdio.h>

main(){
    Celula *lista;
    lista = malloc(sizeof(Celula));
    lista->prox = NULL;
    inserir(3, lista); // o valor de x é 3, e passamos a lista como parâmetro.
}
