struct no{
    char conteudo;
    struct no *sae;
    struct no *sad;
}
typedef struct no No;
//Método para criar a estrutura;
//conteudo, sub-arvore esquerda e sub-arvore de direita
No * criar(char *c, No *e, No *d){
    No *arv = (No*) malloc(sizeof(No));
    arv->conteudo = c;
    arv->sae = e;
    arv->sad = d;
    return arv;
}

main(){
    //Vamos primeiro criar das folhas até a raiz, para isso precisa saber a estrutura da arvore:
    //1°) Criar as folhas
        // a1 não é raiz, mas o primeiro elemento
    No *a1 = criar('d', NULL, NULL);
    // 2°) Criar todas as folhas ou ir no pai, mas não criando o nó seguinto por ter criar a outra estrutura
        //Criar folhas:
        No *a1 = criar('d', NULL, NULL);
        No *a2 = criar('e', NULL, NULL);
        No *a3 = criar('f', NULL, NULL);

    // 3°) Criar os pais das folhas:
        No *a4 = criar('b', NULL, a1);
        No *a5 = criar('c', a2, a3);

    //4°) Como outro nível é o nó raiz, cria-se ele:
        No *a6 = criar('a', a4, a5);

    // Se fosse criar um método só uma variavel:
        No * arvore = criar('a', criar('b,' NULL, criar('d', NULL, NULL)), 
                    criar('c', criar('e', NULL, NULL))
                    criar('f', NULL, NULL));
    return 0;
}
// Obs -> Ruim desse método: se tiver 1000 nós? se precisar adicionar outro elemento na folha1;

