# Python é uma porcaria, nem com Timelimit de 4s esse código passa >:|
minimum,explored,amountFriends,adj=None,None,None,None
def subtract(node):
    queue=[node]
    while queue:
        for i in adj[queue.pop()]:
            amountFriends[i]-=1
            if amountFriends[i]<minimum and not explored[i]:
                explored[i]=1
                queue.insert(0,i)
while 1:
    try:
        [vert,edge,minimum]=list(map(int,input().split()))
        adj=[[] for i in range(vert+1)]
        amountFriends=[0 for i in range(vert+1)]
        for i in range(edge):
            [v1,v2]=list(map(int,input().split()))
            if v1<vert+1:
                adj[v1-1].append(v2-1)
                amountFriends[v1-1]+=1
            if v2<vert+1:
                adj[v2-1].append(v1-1)
                amountFriends[v2-1]+=1
        explored=[0 for i in range(vert+1)]
        for i in range(vert+1):
            if not explored[i] and amountFriends[i]<minimum:
                explored[i]=1
                subtract(i)
        index,tot=-1,0
        for i in range(vert+1):
            if not explored[i] and tot<explored.count(0)-1:
                print(i+1,end=' ')
                tot+=1
            index=i if not explored[i] else index
        print(index+1)
    except EOFError:break
