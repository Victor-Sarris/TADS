#include <stdlib.h>

struct celula{ //celula é a mesma coisa que um nó
    int conteudo;
    struct celula *proximo; // ponteiro para a próxima célula
};

typedef struct celula Celula; // define um tipo chamado Celula | "Celula" é um alias (apelido) para "struct celula"

main(){
    Celula *cabeca; // ponteiro para a cabeça da lista
    cabeca = malloc(sizeof(Celula)); // aloca memória para a cabeça da lista

    cabeca->proximo = NULL; // inicializa o ponteiro para a próxima célula como NULL
    
    Celula *nova;
    nova = malloc(sizeof(Celula));
    nova->conteudo = 5; // atribui o valor 5 à nova célula
    nova->proximo = cabeca->proximo; // aponta a nova célula para o próximo elemento da lista (que é NULL no início)

    cabeca->proximo = nova; // atualiza a cabeça para apontar para a nova célula
}