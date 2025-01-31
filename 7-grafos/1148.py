import heapq

adjVertic,adjWeight,accordingly,origin,destiny=None,None,None,None,None
def Dijkstra(sizeGraph):
    time=[2147483647 for i in range(sizeGraph)]
    time[origin]=0
    queue=[]
    heapq.heappush(queue,[0,origin])
    while queue:
        analyse=heapq.heappop(queue)
        if analyse[0]>time[destiny]-1:return time[destiny]
        for i in range(len(adjVertic[analyse[1]])):
            auxV=adjVertic[analyse[1]][i];auxW=adjWeight[analyse[1]][i]
            if analyse[0]+auxW<time[auxV]:
                time[auxV]=analyse[0]+auxW
                if adjVertic[i]!=destiny:
                    heapq.heappush(queue,[time[auxV],auxV])
    return time[destiny]

while True:
    [vert,edge]=list(map(int,input().split()))
    if not vert and not edge:break
    adjVertic=[[] for i in range(vert)]
    adjWeight=[[] for i in range(vert)]
    acordingly=[[0 for i in range(vert)] for i in range(vert)]
    for i in range(edge):
        [v1,v2,h]=list(map(int,input().split()))
        adjVertic[v1-1].append(v2-1)
        adjWeight[v1-1].append(h)
        acordingly[v1-1][v2-1]=1
        if acordingly[v2-1][v1-1]:
            adjWeight[v1-1][adjVertic[v1-1].index(v2-1)]=0
            adjWeight[v2-1][adjVertic[v2-1].index(v1-1)]=0
    for i in range(int(input())):
        [origin,destiny]=list(map(int,input().split()))
        origin-=1
        destiny-=1
        result=Dijkstra(vert)
        if result==2147483647:print('Nao e possivel entregar a carta')
        else: print(result)
    print()
    adjVertic,adjWeight,acordingly=None,None,None
