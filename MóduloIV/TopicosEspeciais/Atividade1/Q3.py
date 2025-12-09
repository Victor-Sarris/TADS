#crie uma função que receba um estado representando um jogo da velha, a função deve retornar "X" ou "O" conforme quem tenha vencido. Se fico empate, retorna "E" outras situações ou inconsistências retornar "Y"

def verifica_jogo(tabuleiro):
    x_count = sum(linha.count("X") for linha in tabuleiro)
    o_count = sum(linha.count("O") for linha in tabuleiro)
    
    if o_count > x_count or x_count - o_count > 1:
        return "Y"