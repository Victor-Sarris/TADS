#include <stdio.h>
#include <string.h>

char *PrimeiraVogal(char *s){
    const char vogais[] = "aeiou"; //declaracao de um array de caracteres contendo as vogais
    // Pode ser "AEIOU" se quiser considerar vogais maiúsculas também
    int i; // Variável de controle para o loop
    for(i = 0; s[i]!='\0'; i++){ 
        if(strchr(vogais, s[i]) != NULL){ // Verifica se o caractere atual é uma vogal
            // strchr retorna um ponteiro para a primeira ocorrência do caractere na string
            printf("Posicao da vogal na frase: %d\n", i); // Imprime a posição da vogal na frase (indice)
            return &s[i]; // Retorna o endereço da primeira vogal encontrada
        }
    }

    return NULL; // Retorna NULL se não encontrar nenhuma vogal
}

main(){
    char frase[] = "primeira vogal";
    char *ptr; // responsavel por receber o resultado do endereço de memoria da primeira vogal (funcao)
    ptr = PrimeiraVogal(frase);

    if(ptr != NULL){
        printf("Vogal encontrada no endereco: %p.\n", ptr);
    } else{
        printf("A frase informada não possui vogal.\n");
    }
}