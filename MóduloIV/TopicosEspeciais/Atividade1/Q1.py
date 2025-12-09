#Dado os tipos sanguíneos de um doador e de um receptor, escreva um programa ou função para informar se a doação pode ou não acontecer (se é ou não compatível)

entrada1 = str(input("Insira o tipo de sangue doador: "))
entrada2 = str(input("Insira o tipo de sangue receptor: "))
# caixa ALTA
tipo_doador = entrada1.upper()
tipo_receptor = entrada2.upper()

#quebrando doador
abo_doador = tipo_doador[:-1] # todos menos o ultimo
rh_doador = tipo_doador[-1] # somente o ultimo

#quebrando receptor
abo_receptor = tipo_receptor[:-1] #mesma coisa 
rh_receptor = tipo_receptor[-1]

print("Doador:", abo_doador, rh_doador)
print("Receptor:", abo_receptor, rh_receptor)

dicionario_abo = {
    "O": ["O", "A", "B", "AB"],  
    "A": ["A", "AB"],
    "B": ["B", "AB"],
    "AB": ["AB"]
}

def compat_rh(rh_doador, rh_receptor):
    if rh_doador == "-":
        return True
    if rh_doador == "+" and rh_receptor == "+":
        return True
    return False    

# verificacao de dicionario e rh +-
if abo_receptor in dicionario_abo[abo_doador] and compat_rh(rh_doador, rh_receptor):
    print("A doação pode acontecer")
else:
    print("A doação NÃO pode acontecer")