#include <stdlib.h>
#include <stdio.h>

int buscar(arv*a, char c){
    if(a==NULL){
        return 0;
    } else{
        return a->conteudo == c || buscar(a->sae, c) || buscar(a->sad, c); 
        // lembre-se da tabela verdade. '||' é a mesma coisa que 'ou'. Ou seja, quando a primeira senteça for confirmada como verdadeira, o codigo ja vai passar dando com o valor verdadeiro. Por se 'ou', para ser declarado como falso, todas as três sentenças tem que ser falsas 
    }
}


// pesqquisar como fazer a busca de uma arvore generica, onde os nos tem varios filhos 🪽

// metodo de excluir elemento de uma arvore 👇
// devemos verificar ao escrever o método:
// 1 - Verificar se o usuario realmente quer excluir esse nó

int excluir(arv *a, char c){
    if (a==NULL){
        printf("o conteudo do nó já foi apagado")
    } else{
        free(arvore->sae); // ou tambem pode ser: arvore->sae = NULL; 
    }
}

// de acordo com os meus conhecimentos, ficaria mais ou menos assim 👆