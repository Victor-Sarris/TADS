//Boa parte dos compiladores não entendem, a minoria aceita, por isso é melhor fazer isso:
struct no
{
    int conteudo;
    //apelidar com isto para chamar, pq uma lista dinamica aponta para outra lista
    //mas como essa esturutra não foi criada, tem que repetir para apelidar pq não foi criada
    struct no *proximo;
};
//Aí como não colocou, o typedef tem que ser defino aqui, para definir tem que ser assim;
typedef struct no No;
//typedef define por fim em um tipo de dado, veja dps no chat

//Antigamente criamos a referência e definimos, aí usando no struct apelidamos e definimos
//OBS: Ver dps se isso é feito para fazer referência ao próprio tipo de dados;
//OBS2: Tem como fazer uma estrutura de dados que aponta para o próximo elemento, como elemento anterior

//OBS3: 'no' só é o nome da estrutura, a partir do typedef se torna um tipo na linguagem C
