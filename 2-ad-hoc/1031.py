while True:
    p=0 
    x=int(input())
    if x==0:
        break;
    lis_n=[_ for _ in range(1,x+1)]
    while True:
        index=0
        new_lis=[_ for _ in lis_n]
        new_lis.pop(0)
        for _ in range(x-1,1,-1):
            index=(index+p)%_
            new_lis.pop(index)
        if new_lis[0]==13:
            break
        new_lis.clear()
        p+=1
    print(p+1)