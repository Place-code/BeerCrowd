while True:
    x=list(map(int,input().split()))
    if x[0]==0:
        break
    for i in x:
        lis_n=[2]
        mapa=[]
        mapa=[y for y in range(1,i+1)]
        index=0
        for epa in range(i,1,-1):
            pa=lis_n[len(lis_n)-1]-1
            index=(index+pa)%epa
            mapa.pop(index)
            j=lis_n[len(lis_n)-1]+1
            while True:
                pri=True
                for _ in lis_n:
                    if _>j**0.5 or j%_==0:
                        if j%_==0:
                            pri=False
                        break
                if pri:
                    lis_n.append(j)
                    break
                j+=1
        print(mapa[0])
        lis_n.clear()