while (x:=int(input()))!=0:
    lista=[[],[]]
    for i in range(x):
        [v1,v2]=list(map(int,input().split()))
        lista[0].append(v1)
        lista[1].append(v2)
    y=int(input())
    mochila=[0 for i in range(y+1)]
    for i in range(x):
        for j in range(y,lista[1][i]-1,-1):
            mochila[j]=max(mochila[j],mochila[j-lista[1][i]]+lista[0][i])
    print(mochila[y])