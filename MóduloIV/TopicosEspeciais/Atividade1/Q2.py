#crie uma função que receba dois parâmetros: 1) uma lista contendo dicionários e 2) uma chave. A funççao então ordena a lista de forma crescente com base na chave fornecida

def ordenar(dicionario, chave):
    novo_dicionario = sorted(dicionario, key=lambda x: x[chave])
    print(novo_dicionario)
    
lista =[
    {"Nome": "Carlos", "Idade": 28},
    {"Nome": "Vitoria", "Idade": 18},
    {"Nome": "Marcus", "Idade": 23}
]

ordenar(lista, "Idade")
ordenar(lista, "Nome")
