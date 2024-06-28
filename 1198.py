while True:
    try:
        y=input().split()
        y[0]=int(y[0]);y[1]=int(y[1])
        print(y[0]-y[1]) if y[0]-y[1]>0 else print((y[0]-y[1])*-1)
    except:break