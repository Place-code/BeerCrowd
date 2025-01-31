import heapq
list_adj=None

def Dijkstra()->int:
    minVertic=[float('inf')]*len(list_adj)
    minEdge=[[float('inf')]*27 for _ in range(len(list_adj))]
    fila=[]
    heapq.heappush(fila,[0,0,0])
    while fila:
        get=heapq.heappop(fila)
        if get[0]>minVertic[1]-1:return minVertic[1]
        for i in list_adj[get[1]]:
            auxV,auxW,auxI=i[0],i[1],i[2]
            if auxI==get[2]:continue
            if auxW+get[0]<minEdge[auxV][auxI]:
                minEdge[auxV][auxI]=auxW+get[0]
                minVertic[auxV]=auxW+get[0]if auxW+get[0]<minVertic[auxV]else minVertic[auxV]
                if auxV!=1:
                    heapq.heappush(fila,[minEdge[auxV][auxI],auxV,auxI]);
    return minVertic[1]

while(x:=int(input())):
      [init,end]=input().split()
      translate={}
      translate[init]=0
      translate[end]=1
      list_adj=[[],[]]
      for i in range(x):
          [v1,v2,edge]=input().split()
          if not v1 in translate:
              translate[v1]=len(translate)
              list_adj.append([])
          id1=translate[v1]
          if not v2 in translate:
              translate[v2]=len(translate)
              list_adj.append([])
          id2=translate[v2]
          list_adj[id1].append([id2,len(edge),ord(edge[0])-96])
          list_adj[id2].append([id1,len(edge),ord(edge[0])-96])
      temp=Dijkstra()
      print('impossivel')if temp==float('inf') else print(temp)
      list_adj.clear()
