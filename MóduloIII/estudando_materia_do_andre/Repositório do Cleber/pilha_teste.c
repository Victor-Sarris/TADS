#include <stdio.h>
#include <stdlib.h>

struct no{
    int conteudo;
    struct no *proximo;
};
typedef struct no No;

//faça um elemento para inserir na pilha
void inserirPilha(No* inicio, int valor){
    No *novo = (No*) malloc(sizeof(No));
    novo->conteudo = valor;
    novo->proximo = inicio->proximo;
    inicio->proximo = novo;
}

//faça uma função que exiba todos os elementos com for
void exibirPilha(No *inicio){
    No *p;
    for(p = inicio->proximo; p != NULL; p = p->proximo){
        printf("Celula %p -> %d;\n", p, p->conteudo);
    }
}

void apagarPilha(No *ini){
    if(ini->proximo != NULL){
        No *p;
        for(p = ini->proximo; p != NULL; p = p->proximo){
            No *atual = ini->proximo;
            No *sucessor = atual->proximo;
            free(atual);
            ini->proximo = sucessor;
        }
    }else{
        printf("Lista Vazia!");
    }
}

//faça uma função que exclua um elemento da pilha:
void excluirPilha(No *inicio){
    if(inicio->proximo != NULL){
        No *atual = inicio->proximo;
        No *auxiliar = atual->proximo;
        free(atual);
        inicio->proximo = auxiliar;
    }
    else{
        printf("Pilha está vazia!");
    }
}

// Faça uma pilha que busque um valor, retorne o No:
No* buscarElemento(No *inicio, int valor){
    if(inicio->proximo != NULL){
        No *p;
        for(p = inicio->proximo; p != NULL; p = p->proximo){
            if(p->conteudo == valor){
                return p;
            }
        }
    }
    return NULL;
}
int main(){
    No p;
    p.proximo = NULL;

    inserirPilha(&p, 18);
    inserirPilha(&p, 27);
    inserirPilha(&p, 35);

    exibirPilha(&p);
    printf("\n");
    
    No *valor_buscado = buscarElemento(&p, 18);
    printf("\nNo %p -> %d;\n\n", valor_buscado, valor_buscado->conteudo);

    excluirPilha(&p);
    excluirPilha(&p);
    // excluirPilha(&p);
    // excluirPilha(&p);

    exibirPilha(&p);


    return 0;
}