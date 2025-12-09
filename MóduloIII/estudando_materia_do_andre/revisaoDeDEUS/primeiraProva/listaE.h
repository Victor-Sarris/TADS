struct celula{
    int conteudo;
    struct celula *proximo; 
};

typedef struct celula Celula;


void inserir(int x, Celula *ini);
void exibir(Celula *ini);