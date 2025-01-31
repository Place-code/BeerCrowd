dici={}
novo={}
for i in range(int(input())):
    x=int(input())
    dici[x]=0 if x not in dici else dici[x]
    dici[x]+=1 if x in dici else 0
for i in sorted(dici):
    novo[i]=dici[i]
for i,j in novo.items():
    print('{} aparece {} vez(es)'.format(i,j))