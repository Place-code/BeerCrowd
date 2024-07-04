for i in range(int(input())):
    init = input()
    v=a=input().split()
    v=int(v[0])
    a=int(a[1])
    # 
    lis_v=[]
    camino={}
    # 
    for j in range(0,v,1):
        lis_v.append([j,0,0])
    for j in range(a):
        ares=input().split()
        # 
        if camino.get(ares[0])==None:
            camino[ares[0]]=[ares[1]]
        else:
            camino[ares[0]].append(ares[1])
        # 
        if camino.get(ares[1])==None:
            camino[ares[1]]=[ares[0]]
        else:
            camino[ares[1]].append(ares[0])
    posi=init
    dis=1
    ver=False
    lis_v[int(posi)][2]=1
    lis_v[int(posi)][1]=-1
    p=0
    while(True):
        p+=1
        ll=camino.get(str(posi))
        for j in ll:
            if lis_v[int(j)][1]==0:
                lis_v[int(j)][1]=dis
            ver=lis_v[int(j)][2]==0
            if ver:
                posi=lis_v[int(j)][0]
                break
        if ver:
            dis+=1
            lis_v[int(posi)][2]=1
        else:
            dis-=1
            palpite=lis_v[int(posi)][1]
            camino_dis=True
            for j in ll:
                if lis_v[int(j)][1]<palpite:
                    palpite=lis_v[int(j)][1] 
                    posi=j
            if posi==init:
                for j in camino.get(init):
                    camino_dis=lis_v[int(j)][2]==0
                if camino_dis==False:
                    break
    print(p)