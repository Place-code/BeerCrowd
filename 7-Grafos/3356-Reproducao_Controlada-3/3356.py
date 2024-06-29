entry=input().split(" ")
dic={}
for i in range(0,int(entry[1])):
    exist=input().split(" ")
    dic[exist[2]]=[exist[0], exist[1]]
for i in range(0,int(entry[2])):
    output=input().split(" ")
    pai1=output[0]
    pais1=[]
    mae1=output[0]
    maes1=[]
    while True:
        try:
            pai1=dic[pai1][0]
            pais1.append(pai1)
        except:
            try:
                mae1=dic[mae1][1]
                maes1.append(mae1)
            except:
                break
    pai2=output[1]
    pais2=[]
    mae2=output[1]
    maes2=[]
    while True:
        try:
            pai2=dic[pai2][0]
            pais2.append(pai2)
        except:
            try:
                mae2=dic[mae2][1]
                maes2.append(mae2)
            except:
                break
    if len(pais1)<=1:
        pais1=[pai1, pai1]
    else:
        pais1=[dic[pais1[len(pais1)-2]][0],dic[pais1[len(pais1)-2]][1]]
    if len(pais2)<=1:
        pais2=[pai2, pai2]
    else:
        pais2=[dic[pais2[len(pais2)-2]][0],dic[pais2[len(pais2)-2]][1]]
    if len(maes1)<=1:
        maes1=[mae1, mae1]
    else:
        maes1=[dic[maes1[len(maes1)-2]][0],dic[maes1[len(maes1)-2]][1]]
    if len(maes2)<=1:
        maes2=[mae2,mae2]
    else:
        maes2=[dic[maes2[len(maes2)-2]][0],dic[maes2[len(maes2)-2]][1]]
    if pais1[0] in pais2 or pais1[0] in maes2 or maes1[0] in maes2 or maes1[0] in maes2 or pais1[1] in pais2 or pais1[1] in maes2 or maes1[1] in maes2 or maes1[1] in maes2 or pais2[0] in pais1 or pais2[0] in maes1 or maes2[0] in maes1 or maes2[0] in maes1 or pais2[1] in pais1 or pais2[1] in maes1 or maes2[1] in maes1 or maes2[1] in maes1:
        print("verdadeiro")
    else:
        print("falso")