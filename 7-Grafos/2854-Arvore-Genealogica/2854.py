fila_geral=[]
repeat=input().split(' ')
grafo={}
cont=0
for i in range(int(repeat[1])):
    ligacoes=input().split(' ')
    if not ligacoes[0] in grafo:
        grafo[ligacoes[0]]=[]
    grafo[ligacoes[0]].append(ligacoes[2])

    if not ligacoes[2] in grafo:
        grafo[ligacoes[2]]=[]
    grafo[ligacoes[2]].append(ligacoes[0])


for g in grafo:
    fila_geral.append(g)
while fila_geral !=[]:
    inicio=fila_geral[0]
    fila=[inicio]
    processados=[]
    while fila != []:
        atual=fila[0]
        for g in grafo[atual]:
            if not g in fila and not g in processados:
                fila.append(g)
        processados.append(atual)
        fila.pop(0)
    for g in processados:
        fila_geral.remove(g)
    cont+=1
print(cont)
