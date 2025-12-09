#include <stdio.h>
#include <stdlib.h>
//stuct para lista de inteiros
struct no
{
    int conteudo;
    struct no *proximo;
};
//define tipo de dados
typedef struct no No;
//prototipos/ cabeca=ini
void imprime(No *cabeca);
void inserirFim(No *cabeca, int valor);
void liberaFim(No *cabeca);
void buscar(No *cabeca, int valor);
int main(int argc, char const *argv[]){
    //Cria cabeça da lista
    No cabeca;
    cabeca.proximo = NULL; // É nulo porque não tem nenhum elemento
    printf("Quantidade de Bytes:%d;\n", sizeof(No));
    //inserindo elementos:
    inserirFim(&cabeca, 10);
    inserirFim(&cabeca, 20);
    inserirFim(&cabeca, 30);

    //Aguarda o usuario apertar enter    
    system("PAUSE");

    //Imprimir elementos dentro da lista:
    printf("\n-- Imprimindo Elemento dentro da Lista --\n");
    imprime(&cabeca);

    system("PAUSE");

    liberaFim(&cabeca);
    printf("\n-- Imprimindo Elemento dentro da Lista --\n");
    imprime(&cabeca);

    buscar(&cabeca,5);

    system("PAUSE");

    printf("Endereço: %06x", pesquisar(&cabeca, 10));
    return 0;
}
//Dividido em duas etapas:
//1-Criar o elemento ponteiro, alocar espaço na memoria, e colocar valores;
//2-Adicionar elemento dentro da lista dentro no main;

void inserirFim(No *cabeca, int valor){
    //Criando um ponteiro para receber novo elemento na lista cabeca, e alocando um espaço para ele;
    No *novo = (No*) malloc(sizeof(No));

    //inicializa novo elemento, e colocar o valor e afirmar que é o ultimo elemento
    novo->conteudo = valor;
    novo->proximo = NULL; // para apontar que é ultimo elemento
    //se não fosse um ponteiro, seria assim operador de acesso: 
    // novo.conteudo = valor;
    // novo.proximo = NULL;
    
    //varrer a lista no main(cabeca) e inserir o elemento no final da lista:
    No *atual = cabeca;
    while(atual->proximo != NULL){
        atual = atual->proximo;
    }
    // Ao chegar no ultimo elemento da lista cabeca, ele vai e insere o elemento declarado:
    atual->proximo = novo; //->aí como atual mexe com o endereco de cabeça, simplesmente adiciona o endereço de novo aí dentro;
}

//Sempre tem que fazer uma varredura
void imprime(No *cabeca){
    //Pega o o primeiro elemento, já que o primeiro elemento da lista só tem o endereço do primeiro elemeto
    No *atual = cabeca->proximo;
    int i = 0; //contar a quatidade de elementos; 

    //imprime elementos, e atual já é endereço de proximo
    while(atual!=NULL){
        i++;
        printf("Elemento %d da lista: %3d;\n", i, atual->conteudo);
        atual = atual->proximo;
    }
    printf("Quantidade total de elementos: %d;\n", i);
    //diferença: atual!=NULL | atual->proximo == NULL: Na função imprime, usamos `while(atual != NULL)` para garantir que todos os nós sejam percorridos, inclusive o último. Se usássemos `while(atual->proximo != NULL)`, o laço pararia antes de acessar o nó cujo ponteiro "proximo" é NULL, deixando de imprimir o último elemento da lista.
}

//liberar o ultimo elemento da lista:
void liberaFim(No *cabeca){
    //Tem que criar a variável anterior com nó anterior para manter a integridade da cadeia
    No *anterior = cabeca;
    No *atual = cabeca->proximo;
    while(atual->proximo !=NULL){
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Elemento Removido:%d\n", atual->conteudo);
    free(atual);
    //assim pego elemento anterior apagado, e coloco como nulo o campor próximo
    anterior->proximo = NULL;
} 
void liberaInicio(No *cabeca){
    //Tem que criar a variável anterior com nó anterior para manter a integridade da cadeia
    No *anterior = cabeca;
    No *atual = cabeca->proximo;
    printf("Elemento Removido:%d\n", atual->conteudo);
    free(atual);
    //assim pego elemento anterior apagado, e coloco como nulo o campor próximo
    anterior->proximo = NULL;
} 
//procedimento de buscar
void buscar(No *cabeca, int valor){
    No *atual = cabeca->proximo;
    int encontrado = 0;
    while(atual!=NULL){
        if (atual->conteudo == valor){
            printf("\nElemento %d da lista buscado: %06x;\n", atual->conteudo, atual->proximo);
            encontrado = 1; // 1 funciona com true;
            break;
        }
        atual = atual->proximo;
    }
    if(!encontrado){
        printf("\nO Elemento %d é inexistente na lista!", valor);
    }
}

//Função de buscar que retorna um ponteiro
No* pesquisar(No *ini, int valor){
    No *p;
    p = ini->proximo;
    while(p!=NULL && p->conteudo != valor){
        p = p->proximo;
    }
    return p;
}