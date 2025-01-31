end=None
def moveQueen(x,y):
    for i in range(2):
        for j in range(8):
            if (x*i+j*int(not i))*10+y*int(not i)+j*i==end:return True
    auxX=x-y
    auxY=0;
    while(auxX<8 and auxY<8):
        if(auxX*10+auxY==end):return True
        auxX+=1
        auxY+=1
    auxX=x-(7-y)
    auxY=7
    while(auxX<8 and auxY>-1):
        if(auxX*10+auxY==end):return True
        auxX+=1
        auxY-=1
    return False
while((x:=list(map(int,input().split())))and x[0] and x[1] and x[2] and x[3]):
    if x[0]==x[2] and x[1]==x[3]:
        print('0')
        continue 
    end=(x[2]-1)*10+x[3]-1
    if moveQueen(x[0]-1,x[1]-1):print('1')
    else: print('2')

