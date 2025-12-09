#include <stdio.h>
#include <stdlib.h>

struct no{
    int conteudo;
    struct no *proximo;
};
typedef struct no No;

//faça um elemento para inserir na pilha
// utilizado **, porque vamos alterar o ponteiro externo dentro da função
void inserirPilha(No **topo, int valor){ 
    No *novo = (No*) malloc(sizeof(No)); 
    novo->conteudo = valor;
    novo->proximo = *topo;
    *topo = novo;
}
//faça uma função que exclua um elemento da pilha:
void excluirElementoPilha(No **topo){
    if(*topo != NULL){
        No *remover = *topo;
        *topo = remover->proximo;
        free(remover);
    }
    else{
        printf("A pilha está vazia!");
    }
}
//faça uma função que exiba todos os elementos com for
void exibirPilha(No *topo){
    No *p;
    for(p = topo; p != NULL; p = p->proximo){
        printf("Celula %p -> %d;\n", p, p->conteudo);
    }
}

No* buscarElemento(No *topo, int valor){
    if(topo != NULL){
        No *p;
        for(p = topo; p != NULL; p = p->proximo){
            if(p->conteudo == valor){
                return p;
            }
        }
    }
    return NULL;
}
int main(){
    No *topo = NULL;
    inserirPilha(&topo, 2);
    inserirPilha(&topo, 3);
    inserirPilha(&topo, 4);
    exibirPilha(topo);//quando mando neste formato, estou mandando já segundo o tipo, se mandasse com &, ia mandar o endereço do ponteiro a ser mudado

    No *valor_buscado = buscarElemento(topo, 4);
    printf("\n %p -> %d", valor_buscado, valor_buscado->conteudo);
    return 0;
}