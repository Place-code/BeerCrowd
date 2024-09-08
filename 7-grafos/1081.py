def dfs(n):
    fila,espacamento=[n],1
    ok=False
    adj[n]=1
    while True:
        while len(lista_adj[fila[-1]])==0 and len(fila)>1:
            fila.pop()
            espacamento-=1
        ns=fila[-1]
        if len(lista_adj[ns])==0:
            break
        ok=True
        menor=float('inf')
        menor=min(lista_adj[ns])
        menor=int(menor)
        print(" "*(espacamento*2),end='')
        if adj[menor]==0:
            print("{}-{} pathR(G,{})".format(ns,menor,menor))
        else:
            print("{}-{}".format(ns,menor))
        fila.append(menor)
        adj[menor]=1
        lista_adj[ns].remove(menor)
        espacamento+=1
    print() if ok else ''
for i in range(int(input())):
    [x,y]=input().split()
    lista_adj=[set([]) for i in range(int(x))]
    adj=[0 for i in range(int(x))]
    for j in range(int(y)):
        [v1,v2]=input().split()
        lista_adj[int(v1)].add(int(v2))
    print('Caso {}:'.format(i+1))
    for j in range(int(x)):
        dfs(j) if adj[j]==0 else None