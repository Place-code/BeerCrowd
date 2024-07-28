lis=[]
v1=[]
v2=[]
e=0
for i in range(int(input())):
    lis.append([])
    x=input().split()
    lis[i]=[int(j) for j in x]
for i in  lis:
    v1.append(0)
    v2.append(0)
    for j in i:
        v1[len(v1)-1]+=j
    for k in lis:
        v2[len(v2)-1]+=k[e]
    e+=1
palpite=0
cor=[]
for i in range(2):
    if i==0: v=v1
    else: v=v2
    for i in v:
       palpite=i
       index=-1
       for j in v:
            if j==palpite: index+=1
            else: index-=1
       if index<0:
            cor.append(v.index(palpite))
            break
       else:
           v_c=palpite
print(v_c-(palpite-lis[cor[0]][cor[1]]),lis[cor[0]][cor[1]])