
x=[[] for i in range(3)]
su=0
for i in range(3):
    x[i]=list(map(int,input().split()))
    su+=sum(x[i])
print(su)
lis=[['circulo','quadrado','triangulo'],['circulos','quadrados','triangulos']]
lis1=['um','dois','tres']
for i in range(3):
    for j in range(3):
        for k in range(x[i][j]):
            if j>0:
                print(lis1[j],lis[1][i],end=' ')
            else:
                print(lis1[j],lis[0][i],end=' ')

"""
123 0 123
123 123 123
45 45 4

13 0 13
13 13 13
7 7 3
"""
"""
466 245 0 
1234 1644 312 
1860 238 3356
"""
x=[]
while True:
    i=input()
    if i=='0':break
    if len(i.split())>1:
        j=i.split()
        indexs=[0,0]
        indexs[0]=0 if j[1]=='circulo' or j[1]=='circulos' else 1 if j[1]=='quadrado' or j[1]=='quadrados' else 2
        indexs[1]=0 if j[0]=='um' else 1 if j[0]=='dois' else 2
        x[-1][indexs[0]][indexs[1]]+=1
    else:
        x.append([[0 for j in range(3)] for i in range(3)])
for i in x:
    for j in i:
        for k in j:
            print(k,end=' ')
        print()
