struct no{
    char conteudo;
    struct no * sae; //sae = sub-arvore da esquerda
    struct no * sad; // sad = sub-arvore da direita
};

typedef struct no No; // aqui no caso estamos definindo as o tipo das estrutura

No * criar(char *c, No * e, No * d){
    No * arv = malloc(sizeof(No));                // alocamento de memoria
    arv->conteudo = c;
    arv->sae = e;
    arv->sad = d;

    return arv;
};

main(){
    No * a1 = criar('d', null, null); // precisa colocar entre aspas simples porque ele é caracter
    No * a2 = criar('e', null, null);
    No * a3 = criar('f', null, null);
    No * a4 = criar('b', null, a1); // no caso, 'a1' porque é ele é um nó do tipo varchar. No caso, precisamos chamar o endereco de memoria dele para poder referencialo
    No * a5 = criar('c', a2, a3);
    No * a6 = criar('a', a4, a5);
};
