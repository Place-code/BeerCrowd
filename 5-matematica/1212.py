while True:
    x=input().split()
    if x[0]=="0" and x[1]=="0":break
    tem=0
    subir=0
    tam=[len(x[0]),len(x[1])]
    un_maior=False
    un_maior=True if len(x[1])>len(x[0]) else un_maior
    loc=0
    if(un_maior):
        loc=1
    for i in range(2):
        x[i]=list(x[i])
        x[i].reverse()
    for i in range(min(tam)):
        if int(x[1][i])+int(x[0][i])+tem>9: tem=1
        else: tem=0
        if tem !=0: subir+=1
    maior = min(tam)
    while tem==1:
        if maior>len(x[loc])-1: break
        if int(x[loc][maior])+tem>9: 
            tem=1
        else: tem = 0
        if tem !=0: subir+=1
        maior+=1
    if subir==0:
        print('No carry operation.')
    else:
        print('1 carry operation.') if subir==1 else print(subir,'carry operations.')