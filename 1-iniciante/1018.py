x=int(input())
v=[100,50,20,10,5,2,1,0]
deco=[0,0,0,0,0,0,0]
print(x)
for i in range(0,len(v)-1,1):
    for j in range(i+1,len(v),1):
        if x>=v[i]-v[j]:
            deco[i]=1*int(x/v[i])
            x-=v[i]*int(x/v[i])
    print(deco[i],"nota(s) de R$",v[i],end='')
    print(",00")