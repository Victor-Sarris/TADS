from collections import deque
import time

def resolver_jarro_de_agua_simplificado(capacidade_a, capacidade_b, objetivo):
    gerados = 0
    avaliados = 0
    
    """
    Encontra a solução para o problema do jarro de água usando Busca em Largura
    de forma mais enxuta e reutilizável.
    """
    # Fila para a busca (deque é mais eficiente para pop/append no início/fim)
    # A fila armazena caminhos: [[(0,0)], [(4,0)], ...]
    fila = deque([ [(0, 0)] ]) 
    
    # Conjunto para armazenar estados já visitados para evitar loops
    visitados = set([(0, 0)])

    while fila:
        avaliados += 1
        # Pega o caminho mais antigo da fila
        caminho_atual = fila.popleft()
        jarroA, jarroB = caminho_atual[-1]

        # --- VERIFICAÇÃO DO OBJETIVO ---
        if jarroA == objetivo or jarroB == objetivo:
            print("🎉 Solução encontrada! 🎉")
            print("O passo a passo é:")
            for estado in caminho_atual:
                print(f"  Jarro A: {estado[0]}L, Jarro B: {estado[1]}L")
            return

        # --- GERAÇÃO CONCISA DOS PRÓXIMOS ESTADOS ---
        
        # Calcula a quantidade a ser transferida em ambos os sentidos
        transferencia_A_para_B = min(jarroA, capacidade_b - jarroB)
        transferencia_B_para_A = min(jarroB, capacidade_a - jarroA)

        # Lista com todos os 6 movimentos possíveis a partir do estado atual
        proximos_estados = [
            (capacidade_a, jarroB),                                   # 1. Encher A
            (jarroA, capacidade_b),                                   # 2. Encher B
            (0, jarroB),                                              # 3. Esvaziar A
            (jarroA, 0),                                              # 4. Esvaziar B
            (jarroA - transferencia_A_para_B, jarroB + transferencia_A_para_B), # 5. Derramar A->B
            (jarroA + transferencia_B_para_A, jarroB - transferencia_B_para_A)  # 6. Derramar B->A
        ]

        # --- LOOP ÚNICO PARA PROCESSAR OS PRÓXIMOS ESTADOS ---
        for estado in proximos_estados:
            gerados += 1
            
            if estado not in visitados:
                visitados.add(estado)
                
                # Cria o novo caminho adicionando o novo estado
                novo_caminho = caminho_atual + [estado]
                fila.append(novo_caminho)
        time.sleep(1) 
        print("="*40)
        print(f"Estado Atual: Jarro A: {jarroA}L | Jarro B: {jarroB}L")
        print(f"Passos feitos até agora: {len(caminho_atual)-1}")
        print(f"Estados Gerados: {gerados} | Estados Avaliados: {avaliados} | Estados na Pilha: {len(fila)}")
        print(f"Estados ainda na fila: {len(fila)}")
        print("\n")

    print("Não foi possível encontrar uma solução.")

# --- Vamos executar o algoritmo! ---
resolver_jarro_de_agua_simplificado(4, 3, 2)