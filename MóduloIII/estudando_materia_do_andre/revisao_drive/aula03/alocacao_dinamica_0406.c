// Aula 3 do drive
// aqui será a anotação relativa a alocação dinâmica de memória
// alocação dinâmica de memória é feita com malloc, calloc, realloc e free

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    char frase[50];
    char *ptr;

    printf("informe uma frase: ");
    scanf("%49[^\n]s", frase);

    ptr = (char *)malloc(strlen(frase)+1);
    if (ptr == NULL) {
        printf("Erre ao alocar memória. Espaço insuficiente\n");
    } else{
        strcpy(ptr, frase);
        printf("A frase informada foi: %s\n",ptr);
    }
    free(ptr);
}