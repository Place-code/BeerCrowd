board,data=None,None

def Translate(string):
    data.append([None,None])
    data[-1][0]=0 if string[0]=='W' else 1 if string[0]=='P' else 2 if string[0]=='T' else 3 if string[0]=='B' else 4
    data[-1][1]=(ord(string[1])-97)*10+ord(string[2])-ord('0')-1
    board[data[-1][1]%10][data[-1][1]//10]=2

def intersectionHorizontal(xy):
    x,y=xy//10,xy%10-1
    while  y>-1:
        if board[y][x]>1:
            board[y][x]+=1
            break
        board[y][x]=1
        y-=1
    y=xy%10+1
    while y<8:
        if board[y][x]>1:
            board[y][x]+=1
            break
        board[y][x]=1
        y+=1
    x-=1
    y=xy%10
    while x>-1:
        if board[y][x]>1:
            board[y][x]+=1
            break
        board[y][x]=1
        x-=1
    x=xy//10+1
    while x<8:
        if board[y][x]>1:
            board[y][x]+=1
            break
        board[y][x]=1
        x+=1
def intersectionVertical(xy):
    x,y=xy//10-1,xy%10-1
    while x>-1 and y>-1:
        if board[y][x]>1:
            board[y][x]+=1
            break
        board[y][x]=1
        x-=1
        y-=1
    x,y=xy//10+1,xy%10-1
    while x<8 and y>-1:
        if board[y][x]>1:
            board[y][x]+=1
            break
        board[y][x]=1
        x+=1
        y-=1
    x,y=xy//10-1,xy%10+1
    while x>-1 and y<8:
        if board[y][x]>1:
            board[y][x]+=1
            break
        board[y][x]=1
        x-=1
        y+=1
    x,y=xy//10+1,xy%10+1
    while x<8 and y<8:
        if board[y][x]>1:
            board[y][x]+=1
            break
        board[y][x]=1
        x+=1
        y+=1
def intersectionKing(xy):
    for i in range(3):
        x,y=xy//10-1,xy%10-1+i
        if y<0 or y>7:continue
        for j in range(3):
            if x+j<0 or x+j>7 or (x+j)*10+y==xy:continue
            if board[y][x+j]>1:board[y][x+j]+=1
            else: board[y][x+j]=1
def intersectionPawn(xy):
    x,y=xy//10,xy%10-1
    if y<0:return;
    if x+1<8:
        if board[y][x+1]>1:board[y][x+1]+=1
        else: board[y][x+1]=1
    if x-1>-1:
        if board[y][x-1]>1:board[y][x-1]+=1
        else: board[y][x-1]=1
def intersections():
    for i in data:
        if i[0]==0:intersectionKing(i[1])
        elif i[0]==1: intersectionPawn(i[1])
        elif i[0]==2 or i[0]==4: intersectionHorizontal(i[1])
        if i[0]==3 or i[0]==4:intersectionVertical(i[1])
    for i in data:
        board[i[1]%10][i[1]//10]-=2
def inCheck(xy):
    for i in range(3):
        x,y=xy//10-1,xy%10-1+i
        if y<0 or y>7:continue
        for j in range(3):
            if x+j<0 or x+j>7:continue
            if not board[y][x+j]:return 0
    return 1
while 1:
    try:
        input()
        data=[]
        board=[[0 for i in range(8)]for j in range(8)]
        for i in input().split():Translate(i)
        intersections()
        King=input()
        print('NAO') if not inCheck((ord(King[1])-97)*10+ord(King[2])-ord('0')-1) else print('SIM')
        board,data=None,None
    except EOFError:break
