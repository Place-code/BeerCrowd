troca={}
[x,y,z]=list(map(int,input().split()))
adj=[[] for i in range(x)]
for i in range(y):
    v=input().split()
    for j in range(3):
        troca[v[j]]=len(troca) if v[j] not in troca else troca[v[j]]
    adj[troca[v[2]]][0:0]=troca[v[0]],troca[v[1]]
for i in range(z):
    [v1,v2]=input().split()
    andados=[0 for i in range(x)]
    andados[troca[v1]]=andados[troca[v2]]=1
    fila=[troca[v1],troca[v2]]
    sim=False
    while True:
        for j in adj[fila[-1]]:
            if andados[j]==1:
                sim=True
                fila.clear()
                break
            fila.insert(0,j)
            andados[j]=1
        if sim:break
        fila.pop()
        if len(fila)==0:
            break
    print("verdadeiro") if sim else print("falso")