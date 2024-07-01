x=input().split(" ")
x=int(x[1])
arestas={}
for i in range(x):
    vertices=input().split(" ")
    if not vertices[0] in arestas:
        arestas[vertices[0]]=[]
    arestas[vertices[0]].append(vertices[1])
    if not vertices[1] in arestas:
        arestas[vertices[1]]=[]
    arestas[vertices[1]].append(vertices[0])
def bfs(arestas,Entrada, said):    
    inicio=Entrada
    final=said
    fila=[inicio]
    processados=[]
    licacon={}
    licacon[inicio]=0
    while fila !=[]:
        atual=fila[0]
        for i in arestas[atual]:
            if not i in processados and not i in fila:
                fila.append(i)
                try:
                    if licacon[i]> licacon[i]:
                        licacon[i]=licacon[atual]+1 
                except:
                    licacon[i]=licacon[atual]+1
        fila.pop(0)
        processados.append(atual)
        if atual == final:
            break
    return int(licacon[said])
numerod1=bfs(arestas, "Entrada", "*")
numerod2=bfs(arestas, "Saida", "*")
print(numerod1+numerod2)