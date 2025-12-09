"""
Atualizações propostas pelo professor 30/10/2025:
- Migrar da busca cega (largura) para busca informada (heurística gulosa) ✅
- Adicionar uma visualização esquemática do crescimento da fila ✅
- Alterar o algoritmo de busca de largura para profunidade ✅
- Revisar a estrutura de navegação no Poplet ✅

Proposta do professor 06/11/2025: 
- Acompanhar a evolução dos tamanhos das listas de estados interativamente ✅
    > Gerados ✅
    > Avaliados ✅
    > Total ✅
    
    seria no caso eu conseguir acompanhar o estado atual, o numero de passos que o algoritmo já fez e também o número que ele ainda vai percorrer, para eu ter uma noção do tamanho da busca que ele está fazendo.

- Criar versão alterada p/ busca em profundiade ✅
- Comparar o desempenho quanto ao uso de recursos e quanto as soluções encontradas ( como? eu não sei ainda!)

    seria no caso eu ter dois algoritmos que de largura e profundidade, e eu conseguir comparar o desempenho dos dois, tanto em uso de recursos (memória, processamento) quanto em soluções encontradas (tempo para encontrar a solução, número de passos para encontrar a solução).
"""
import time


from collections import deque

def ResolverJarro(capacidade_a, capacidade_b, objetivo):
    # variáveis para controle de contagem 
    gerados = 0
    avaliados = 0
    
    
    # Cria a pilha (deque) com o estado inicial (0,0)
    pilha = [[(0, 0)]] 
    
    # Metodo de avaliacao heuristica
    def heuristica(JarroA, JarroB, objetivo):
        return min(abs(objetivo - JarroA), abs(objetivo - JarroB))
    
    # Guarda os estados já visitados para evitar repetições
    visitados = set([(0, 0)])


    while pilha:
        # Retira o último caminho da pilha (busca em profundidade, ou seja, busca gulosa tlgd?)
        caminho_atual = pilha.pop()
        
        avaliados += 1
        
        jarroA, jarroB = caminho_atual[-1]

        # Verifica se atingiu o objetivo
        if jarroA == objetivo or jarroB == objetivo:
            print("\n")
            print("Solução encontrada!\n")
            print("O passo a passo é:\n")
            for estado in caminho_atual:
                time.sleep(1)
                print(f"Jarro A: {estado[0]}L, Jarro B: {estado[1]}L")
                print("="*30)
                print("\n")
            return

        # Calcula quanto pode ser transferido de um jarro para outro
        transferencia_A_para_B = min(jarroA, capacidade_b - jarroB)
        transferencia_B_para_A = min(jarroB, capacidade_a - jarroA)


        # Gera todos os possíveis próximos estados
        proximos_estados = [
            (capacidade_a, jarroB),  # Encher A
            (jarroA, capacidade_b),  # Encher B
            (0, jarroB),              # Esvaziar A
            (jarroA, 0),              # Esvaziar B
            (jarroA - transferencia_A_para_B, jarroB + transferencia_A_para_B),  # A → B
            (jarroA + transferencia_B_para_A, jarroB - transferencia_B_para_A)   # B → A
        ]
        
        proximos_estados.sort(key=lambda x: heuristica(x[0], x[1], objetivo))

        # Adiciona novos estados na fila se ainda não foram visitados
        for estado in proximos_estados:
            gerados += 1
            
            if estado not in visitados:
                visitados.add(estado)
                
                
                
                # cria um novo caminho adicionando o estado atual   
                novo_caminho = caminho_atual + [estado]
                pilha.append(novo_caminho)
        
        time.sleep(1) 
        print("="*40)
        print(f"Estado Atual: Jarro A: {jarroA}L | Jarro B: {jarroB}L")
        print(f"Passos feitos até agora: {len(caminho_atual)-1}")
        print(f"Estados Gerados: {gerados} | Estados Avaliados: {avaliados} | Estados na Pilha: {len(pilha)}")
        print(f"Estados ainda na pilha: {len(pilha)}")
        # print("="*40)
        print("\n")
                
        # print(f"Tamanho da pilha: {len(pilha)} | Último estado: {caminho_atual[-1]}")


    print("Não foi possível encontrar uma solução.")

ResolverJarro(4, 3, 2)