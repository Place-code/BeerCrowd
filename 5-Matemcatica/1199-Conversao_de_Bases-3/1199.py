while True:    
    x=input()
    if x == "-1":
        break
    hexde="0 1 2 3 4 5 6 7 8 9 a b c d e f".split(" ")
    try:
        if x[1]=="x":
            Hexa=True
        else:
            Hexa=False
    except:
        if x[0]=="x":
            Hexa=True
        else:
            Hexa=False
    l=[0]
    if Hexa:
        x=x[2:]
        co=len(x)-1
        for i in x:
            l.append(hexde.index(i)*(16**co))
            co-=1
        print(sum(l))
    else:
        print(str(hex(int(x)))[:2], end="")
        print(str(hex(int(x))).upper()[2:])