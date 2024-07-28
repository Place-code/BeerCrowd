v=input().split()
pmg=input()
v1=input().split()
vv=[int(i) for i in v1]
indexs=[0,0,0]
muralhas=[int(v[1])]
posi=0
neg=0
for i in pmg:
    if i=='P':
        posi=0
    elif i=='M':
        posi=1
    elif i=='G':
        posi=2
    if indexs[posi]>len(muralhas)-1:
        muralhas.append(int(v[1]))
    if muralhas[indexs[posi]]<vv[posi]:
        while muralhas[indexs[posi]]<vv[posi]:
            indexs[posi]+=1
            muralhas.append(int(v[1])) if indexs[posi]>len(muralhas)-1 else muralhas
    muralhas[indexs[posi]]-=vv[posi]
    if muralhas[indexs[posi]]<0:
        neg=muralhas[indexs[posi]]
        while muralhas[indexs[posi]]<0:
            indexs[posi]+=1
            muralhas.append(int(v[1])) if indexs[posi]>len(muralhas)-1 else muralhas
            muralhas[indexs[posi]]+=neg
            neg+=muralhas[indexs[posi]]
print(len(muralhas))