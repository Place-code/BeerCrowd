def bfs(init,end):
    fila,aux=[init],[]
    zero=[0 for i in range(x[0])]
    para=True
    cont=0
    while para:
        while len(fila)>0:
            for i in matrix[fila[0]]:
                if i==end:
                    para=False
                    break
                elif zero[i]==0:
                    aux.append(i)
                    zero[i]=1
            if not para:
                break
            fila.pop(0)
        fila=[x for x in aux]
        aux.clear()
        cont+=1
    return cont
x=list(map(int,input().split()))
troca={}
matrix=[[] for i in range(x[0])]
for i in range(x[1]):
    [v1,v2]=input().split()
    if not v1 in troca:
        troca[v1]=len(troca)
    if not v2 in troca:
        troca[v2]=len(troca)
    matrix[troca[v1]].append(troca[v2])
    matrix[troca[v2]].append(troca[v1])
print(bfs(troca["Entrada"],troca["*"])+bfs(troca["*"],troca["Saida"]))