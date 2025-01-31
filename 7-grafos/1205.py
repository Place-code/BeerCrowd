import heapq

adj,german=None,None
def Dijkstra(source,end,munition,amountVertic):
    amountBullets=[-1]*amountVertic
    amountBullets[source]=munition-german[source]
    fila=[]
    heapq.heappush(fila,[amountBullets[source]*-1,source])
    while fila:
        aux=heapq.heappop(fila)
        aux[0]*=-1
        if aux[0]<amountBullets[end]+1:return amountBullets[end]
        for i in adj[aux[1]]:
            if amountBullets[i]<aux[0]-german[i]:
                amountBullets[i]=aux[0]-german[i]
                heapq.heappush(fila,[amountBullets[i]*-1,i])
    return amountBullets[end]
while True:
    try:
        x=list(map(float,input().split()))
        adj=[[] for i in range(int(x[0]))]
        for i in range(int(x[1])):
            [v1,v2]=list(map(int,input().split()))
            adj[v1-1].append(v2-1)
            adj[v2-1].append(v1-1)
        german=[0]*int(x[0])
        for i in list(map(int,input().split()))[1:]:
            german[i-1]+=1
        [init,end]=list(map(int,input().split()))
        print("{:.3f}".format(x[3]**(int(x[2])-Dijkstra(init-1,end-1,int(x[2]),int(x[0])))))
        adj.clear()
        german,adj=None,None
    except:break
