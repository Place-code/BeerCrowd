while True:    
    x=input().split()
    if x == ["0", "0"]:
        break
    l1=[]
    l2=[]
    e=0
    count1=0
    for i in x[0]:
        l1.append(int(i))
    for i in x[1]:
        l2.append(int(i))
    if len(l1)<9:
        for i in range(0, 9-len(l1)):
            l1.insert(0, 0)
    if len(l2)<9:
        for i in range(0, 9-len(l2)):
            l2.insert(0, 0)
    for i in range(9-1, -1, -1):
        n1=l1[i]
        n2=l2[i]
        if n1+n2+e >9:
            e=1
            count1+=1
        else:
            e=0
    if count1==0:
        count1="No"
    if count1==1 or count1=="No":
        print(f"{count1} carry operation.")
    else:
        print(f"{count1} carry operations.")