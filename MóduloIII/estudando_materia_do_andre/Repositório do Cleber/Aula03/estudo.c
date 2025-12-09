// Aviso, pede para fazer a verificação por trecho;
#include <stddef.h>
#include <stdio.h>
struct no
{
    int conteudo;
    struct  no *proximo;
};
typedef struct no No;

//passagem de parametro por valor -> faz uma cópia do parametro
//passagem do valor por referência -> utiliza-se ponteiros

//assinatura do método
//Inserir só um elemento
void inserir(int x, No * ini){
    No *novo;
    novo = malloc(sizeof(No));
    novo -> conteudo = x;
    //novo -> proximo = NULL; -> esta parte só faz a inserção de só um elemento
    novo -> proximo = ini -> proximo; //aqui funciona tanto para primeiro em diante;
    ini -> proximo = novo;
    //encadeiar é próximo campo
}
void exibir(No *ini){
    //No *p = NULL; //ver porque tem que colocar null
    No *p;
    for(p = ini -> proximo; p != NULL; p = p -> proximo){ // ver a detalhe esse for
        print("%d", p->conteudo);
    }
}
main(){
    
    // objetivo de guardar o endereço de inicio, porque precisamos o endereço do primeiro para percorrer a lista
    inserir(5, inicio);
    inserir(3, inicio);
    exibir(inicio); // -> precisa do parametro de inicio para saber onde começa
}
