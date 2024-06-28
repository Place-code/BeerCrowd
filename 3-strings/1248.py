#Resulta em erro de apresentação
x=int(input())
for i in range(x):
    txt=[input() for j in range(3)]
    txt2=txt[1]+txt[2]
    dici={}
    for j in txt[0]:
        dici[j]=-1
    verdade=True
    for j in txt2:
        if j not in dici.keys():
            print("CHEATER",'\r')
            verdade=False
            break
        else:
            dici[j]+=1
    alfa=[]
    if verdade==True:
        for j,k in dici.items():
            if k<0: 
                alfa.append(j)
        alfa.sort()
        if(len(alfa)==0):print("\r")
        else:
            for j in range(len(alfa)):
                if j<len(alfa)-1:
                    print(alfa[j],end='')
                else:
                    print(alfa[j],'\r')