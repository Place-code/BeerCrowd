for i in range(0,int(input())):
    x=input().split(" ")
    x.pop(0)
    j=[]
    for g in x:
        j.append(int(g))
    x=[]
    med=sum(j)/len(j)
    for g in j:
        if g > med:
            x.append(g)
    print(f"{(len(x)/len(j))*100:.3f}%")