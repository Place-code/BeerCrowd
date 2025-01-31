while True:
    [g,p]=list(map(int,input().split()))
    array=[[] for i in range(g)]
    if g==0 and p==0: break
    ant,e=None,None
    for j in range(g):
        array[j]=[0 for i in range(p)]
        e=0
        for i in list(map(int,input().split())):
            array[j][i-1]=e
            e+=1
    for i in range(int(input())):
        e=0
        ant=0
        placar,fila=[0 for i in range(p)],[]
        for j in list(map(int,input().split()))[1:]:
            for k in range(g):
                placar[array[k][e]]+=j
                if placar[array[k][e]]>ant:
                    fila.clear()
                    fila.append(array[k][e]+1)
                    ant=placar[array[k][e]]
                elif ant==placar[array[k][e]]:
                    fila.append(array[k][e]+1)
            e+=1
        fila.sort()
        fila.reverse()
        while len(fila)>1:
            print(fila.pop(),end=' ')
        print(fila.pop())