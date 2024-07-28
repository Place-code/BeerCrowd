#TLE
pode=True
reuslt=0
while True:
    cit=[]
    x=list(map(int,input().split()))
    if x[0]==0 and x[1]==0:
        break
    y=list(map(int,input().split()))
    # 
    for i in y:
        for j in y:
            pode=True
            result=i-j
            if result<0: result*=-1
            for k in cit:
                pode=False if k==result else pode
            if pode:
                cit.append(result)
    print('N') if len(cit)<=x[0] else print('Y')