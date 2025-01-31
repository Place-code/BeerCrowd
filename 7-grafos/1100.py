queue,board,init,end=None,None,None,None

def moveKnight(x,y):
    tot=[]
    for i in range(2):
        if x+i+1<9 and y+2-i<9 and not board[y+2-i][x+i+1]:
            tot.append((x+i+1)*10+y+2-i)
            board[y+2-i][x+i+1]=1
        if x+i+1<9 and y-2+i>0 and not board[y-2+i][x+i+1]:
            tot.append((x+i+1)*10+y-2+i)
            board[y-2+i][x+i+1]=1
    for i in range(2):
        if x-i-1>0 and y+2-i<9 and not board[y+2-i][x-i-1]:
            tot.append((x-i-1)*10+y+2-i)
            board[y+2-i][x-i-1]=1
        if x-i-1>0 and y-2+i>0 and not board[y-2+i][x-i-1]:
            tot.append((x-i-1)*10+y-2+i)
            board[y-2+i][x-i-1]=1
    return tot
def bfs(cont,queue):
    aux=[]
    while (len(queue)):
        if(queue[-1]==end):
            print("To get from {}{} to {}{} takes {} knight moves.".format(chr(int((init-init%10)/10+96)),init%10,chr(int((end-end%10)/10+96)),end%10,cont))
            return
        for i in moveKnight(int((queue[-1]-queue[-1]%10)/10),queue[-1]%10):
            aux.append(i)
            #print(chr(int((i-i%10)/10)+96)+str(i%10))
        queue.pop()
    queue=aux.copy()
    aux.clear()
    bfs(cont+1,queue)
while 1:
    try:x=input()
    except:break
    init=(ord(x[0])-96)*10+int(x[1])
    end=(ord(x[3])-96)*10+int(x[4])
    queue=[init]
    board=[[0 for i in range(10)] for j in range(10)]
    board[init%10][int((init-init%10)/10)]=1
    bfs(0,queue)
