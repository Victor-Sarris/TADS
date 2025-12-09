struct no{
    int conteudo;
    struct no *prox;
}

typedef struct no No;

int main(){
    No *lista;
    lista = malloc(sizeof(No));
    if (lista == NULL){
        printf("Erro ao fazer alocacao de memoria");
        return 1;
    }
    
    lista->prox = NULL;
    inserir(3, lista);
    
    return 0;
}

void inserir(int x, No *ini){
    No *novo;
    novo = malloc(sizeof(No));
    novo->conteudo = x;
    novo->prox = ini->prox;
    ini->prox = novo;
}