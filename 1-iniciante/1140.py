while True:
    x=int(input())
    if x==0:
        break
    for i in range(1,x+1,1):
        if(i!=x): print(i,end=' ')
        else: print(i)