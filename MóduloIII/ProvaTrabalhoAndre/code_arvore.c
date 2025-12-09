#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char conteudo;
    struct no *sae; // subárvore à esquerda
    struct no *sad; // subárvore à direita
} Arv;

// Cria um novo nó
Arv *criar(char c, Arv *e, Arv *d) {
    Arv *arv = (Arv *) malloc(sizeof(Arv));
    arv->conteudo = c;
    arv->sae = e;
    arv->sad = d;
    return arv;
}

// Exibe a árvore em formato <raiz<esq><dir>>
void exibir(Arv *a) {
    if (a != NULL) {
        printf("<%c", a->conteudo);
        exibir(a->sae);
        exibir(a->sad);
        printf(">");
    } else {
        printf("<>");
    }
}

// Retorna a altura da árvore (-1 para árvore vazia)
int altura(Arv *a) {
    if (a == NULL) {
        return -1;
    } else {
        int esq = altura(a->sae);
        int dir = altura(a->sad);
        return (esq > dir ? esq : dir) + 1;
    }
}

// Busca um caractere na árvore (retorna 1 se encontrar, senão 0)
int buscar(Arv *a, char c) {
    if (a == NULL) {
        return 0;
    }
    if (a->conteudo == c) {
        return 1;
    }
    return buscar(a->sae, c) || buscar(a->sad, c);
}
// Função que remove um nó da árvore genérica, reorganizando seus filhos e liberando a memória corretamente mesmo sem depender de ordenação (não precisa ser ABB).

Arv* remover(Arv *a, char c) {
    if (a == NULL) return NULL;

    if (a->conteudo == c) {
        // CASO 1: folha
        if (a->sae == NULL && a->sad == NULL) {
            free(a);
            return NULL;
        }

        // CASO 2: um filho
        if (a->sae == NULL) {
            Arv *temp = a->sad;
            free(a);
            return temp;
        }
        if (a->sad == NULL) {
            Arv *temp = a->sae;
            free(a);
            return temp;
        }

        // CASO 3: dois filhos
        Arv *substituto = a->sad;
        Arv *esquerda = a->sae;

        // Encontra o ponto mais à esquerda do substituto para anexar a subárvore esquerda
        Arv *temp = substituto;
        while (temp->sae != NULL) {
            temp = temp->sae;
        }
        temp->sae = esquerda;

        free(a);
        return substituto;
    }

    // Aplica a função recursivamente nos filhos
    a->sae = remover(a->sae, c);
    a->sad = remover(a->sad, c);

    return a;
}


// Exemplo de uso
int main() {
    Arv *a = criar('A',
                criar('B',
                    criar('D', NULL, NULL),
                    criar('E', NULL, NULL)),
                criar('C',
                    NULL,
                    criar('F', NULL, NULL)));

    printf("Árvore: ");
    exibir(a);
    printf("\nAltura: %d\n", altura(a));
    printf("Buscar 'E': %d\n", buscar(a, 'E'));
    printf("Buscar 'Z': %d\n", buscar(a, 'Z'));
    
    // Remover um elemento da árvore
    a = remover(a, 'B');
    printf("\nÁrvore após remover 'B': ");
    exibir(a);
    printf("\nAltura após remoção: %d\n", altura(a));

    return 0;
}
