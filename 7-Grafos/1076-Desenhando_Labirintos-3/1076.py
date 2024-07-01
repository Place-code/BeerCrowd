for i in range(int(input())):
    grafo={}
    h=0
    inicio=input()
    repeat=input().split(' ')
    for i in range(int(repeat[1])):
        ligacoes = input().split(' ')
        if not ligacoes[0] in grafo:
            grafo[ligacoes[0]]=[]

        if ligacoes[1] in grafo[ligacoes[0]]:
            h+=1
        grafo[ligacoes[0]].append(ligacoes[1])



        if not ligacoes[1] in grafo:
            grafo[ligacoes[1]]=[]
            
        if ligacoes[0] in grafo[ligacoes[1]]:
            h+=1
        grafo[ligacoes[1]].append(ligacoes[0])

    
    fila=[inicio]
    processados=[]
    atual=inicio
    caminho={inicio:0}
    tamanhos=[]
    while fila != []:
        atual=fila[0]
        for i in grafo[atual]:
            if not i in fila and not i in processados:
                fila.append(i)
                caminho[i]=caminho[atual]+1
                tamanhos.append(caminho[atual]+1)
            processados.append(atual)
        fila.pop(0)
            
    tamanhos_de_arestas=int(repeat[1])-(h/2)
    print(int(max(tamanhos)*2+(tamanhos_de_arestas-max(tamanhos))*2))