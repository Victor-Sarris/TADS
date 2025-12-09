#include <stdio.h>
#include <stdlib.h>

struct no{
    int conteudo;
    struct no *proximo;
};
typedef struct no No;

void inserirFila(No **ini, int valor){
    No *novo = (No*) malloc(sizeof(No));
    novo->conteudo = valor;
    novo->proximo = NULL;
    if(*ini == NULL){
        *ini = novo;
    }else{
        No *p = *ini;
        while (p->proximo != NULL)
        {
            p = p->proximo;
        }
        p->proximo = novo;
    }
} 
void excluirElementoFila(No **ini){
    if(*ini != NULL){
        No *remover = *ini;
        *ini = remover->proximo;
        free(remover);
    }
    else{
        printf("Lista Vazia!");
    }
}

void apagarFila(No **ini){
    if(*ini != NULL){
        No *p;
        for(p = *ini; p != NULL; p = p->proximo){
            No *elemento_removido = *ini;
            *ini = elemento_removido->proximo;
            free(elemento_removido);
        }
    }else{
        printf("Fila Vazia!\n");
    }
}
void exibirFila(No *inicio){
    if (inicio != NULL)
    {
        No *p;
        for(p = inicio; p != NULL; p = p->proximo)
        {
            printf("Elemento: %d;\n", p->conteudo);
        }
    } else{
        printf("Lista Vazia!");
    }
}

int main(){
    No *inicio = NULL;
    inserirFila(&inicio, 15);
    inserirFila(&inicio, 20);
    inserirFila(&inicio, 25);

    exibirFila(inicio);

    excluirElementoFila(&inicio);
    printf("\n");
    exibirFila(inicio);

    apagarFila(&inicio);
    printf("\n");
    exibirFila(inicio);
    return 0;
}