#include <stddef.h>
#include <stdio.h>
struct no
{
    int conteudo;
    struct  no *proximo;
};
typedef struct no No;
// 1. A seguinte versão de insere funciona? Justifique.
void insere(int x, No *p){
    //Desta maneira, se ele insere, mas o valor se destroi dps sair do procedimento
    No novo; // e para alocar espaço tem que ser um ponteiro
    //tem que alocar espaço usando o malloc
    novo.conteudo = x; // operador de acesso, quando não é ponteiro
    novo.proximo = p -> proximo; // seta quando é ponteiro
    p-> proximo = &novo;
}
// 1. A seguinte versão de insere funciona? Justifique.
// 2. Observe a imagem na dentro da pasta e responda, de forma técnica, onde a estrutura
// acima é iniciado e finalizada?
//Nó cabeça é para estruturar inicio da estrutura, em quem ela referencia o elemento próximo para inserção dos elementos, e no fim o campo próximo é nulo, logo tem que falar no campo próximo para justificar.

// 3. Explique em que condições uma lista dinâmica(encadeada) está cheia.

// 4. Observe o procedimento abaixo e informe o seu objetivo. Além disso,
//comente sobre o seu desempenho.
void x(No *p, No *ini){
    No *m;
    m = p-> proximo;

    if(m -> proximo == NULL){
        p->proximo = NULL;
    }
    else{
        p->proximo = m->proximo;
    }
}
//5. Porque quando usamos a alocação dinamica podemos utilizar variaveis locais?