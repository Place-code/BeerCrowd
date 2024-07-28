while True:
    x=input().split()
    if x[0]=='*':
        break
    nao=True
    l=ord(x[0][0])
    if(l<91): dif=l+32
    elif(l>96): dif=l-32
    for _ in x:
        if ord(_[0])!=l and ord(_[0])!=dif:
            nao=False
            break
    res='N'
    res='Y' if nao else res
    print(res)