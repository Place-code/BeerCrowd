for i in range(int(input())):    
    x=input().split()
    x1=int(x[0])
    x2=int(x[1])
    maix=0
    omai=max(x1,x2)
    omin=min(x1,x2)
    reso=0
    while omin !=0:
        omai, omin = omin, omai % omin
    print(omai)