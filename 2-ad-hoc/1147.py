cont=0
matrix=[]
cavalo=None
epa=1
while True:
    x=input()
    if x=='0':
        break
    if cont==0:
        cavalo=[int(x[0])-1,ord(x[1])-97]
        for i in range(8):
            matrix.append([0,0,0,0,0,0,0,0])
    elif(x[0]!="0"):
        if ord(x[1])-96<=7:matrix[int(x[0])-2][ord(x[1])-96]=1
        if ord(x[1])-98>=0:matrix[int(x[0])-2][ord(x[1])-98]=1
    if cont==8:
        movi=0
        for i in range(2):
            if cavalo[0]+2-i<=7:
                if cavalo[1]+1+i<=7: movi+=1 if matrix[cavalo[0]+2-i][cavalo[1]+1+i]==0 else 0
                if cavalo[1]-1-i>=0: movi+=1 if matrix[cavalo[0]+2-i][cavalo[1]-1-i]==0 else 0
            if cavalo[0]-2+i>=0:
                if cavalo[1]+1+i<=7: movi+=1 if matrix[cavalo[0]-2+i][cavalo[1]+1+i]==0 else 0
                if cavalo[1]-1-i>=0: movi+=1 if matrix[cavalo[0]-2+i][cavalo[1]-1-i]==0 else 0
        print('Caso de Teste #{}: {} movimento(s).'.format(epa,movi))
        cont=-1
        epa+=1
        matrix.clear()
        cavalo=None
    cont+=1