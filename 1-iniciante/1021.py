n=float(input())
v=[[100,50,20,10,5,2],[1,0.5,0.25,0.1,0.05,0.01]]
res=0
prin=""
for i in range(2):
    if i==0: prin ="NOTA"
    else: prin="MOEDA"
    print(prin,end='')
    print('S:')
    prin=prin.lower()
    prin+="(s)"
    for j in v[i]:
        while(n>j-0.009):
            res+=1
            n-=j
        print(res, prin, "de R$", f'{j:.2f}')
        res=0