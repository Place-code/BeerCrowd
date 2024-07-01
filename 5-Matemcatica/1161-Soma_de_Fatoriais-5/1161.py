while True:    
    try:    
        x1, x2, = input().split()
        x1=int(x1)
        x2=int(x2)
        for i in range(x1-1, 0, -1):
            x1*=i
        for i in range(x2-1, 0, -1):
            x2*=i
        if x1 ==0:
            x1=1
        if x2 ==0:
            x2=1
        print(x1+x2)
    except:
        break