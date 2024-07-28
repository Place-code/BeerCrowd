while True:
    x=list(map(int,input().split()))
    if x[0]==0 and x[1]==0:
        break
    pode=True
    v=list(map(int,input().split()))
    for _ in range(x[1]):
        index=list(map(int,input().split()))
        v[index[0]-1]-=index[2]
        v[index[1]-1]+=index[2]
    for _ in v:
        if _<0:
            pode=False
            break
    print('S') if pode else print('N')