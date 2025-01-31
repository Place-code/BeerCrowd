matrix,x,y=None,None,None
def check():
    for i in range(x):
        temp=1
        for j in range(y):
            temp=matrix[j][i] if temp else 0
        if temp:return 1
    return 0
while(1):
    [x,y]=list(map(int,input().split()))
    if not x and not y:break
    matrix=[[0 for j in range(x)] for i in range(y)]
    for i in range(y):
        index=0
        for j in input().split():
            matrix[i][index]=int(j)
            index+=1
    print('yes') if check() else print('no')
    matrix=None
