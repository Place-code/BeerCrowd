while True:
    try:
        inp=input()
    except EOFError:
        break
    inp=inp.split()
    fila=[]
    capa=[0 for i in range(26)]
    for i in range(len(inp[0])):
        while True:
            ordem=int(len(inp[0])/2) if i==0 else capa[ord(fila[-1])-65]
            [index1,index2]=[ordem,ordem]
            asc=[0,0]
            for j in range(len(inp[0])):
                if inp[1][index1]==inp[0][i] or inp[1][index2]==inp[0][i]:
                    break
                elif asc[0]!=0 and asc[1]!=0:
                    break
                index1-=1 if index1>0 else 0
                index2+=1 if index2<len(inp[0])-1 else 0
                asc[0]=capa[ord(inp[1][index1])-65] if index1>0 else 1
                asc[1]=capa[ord(inp[1][index2])-65] if index2<len(inp[0])-1 else 1
            if inp[1][index1]==inp[0][i] or inp[1][index2]==inp[0][i]:
                capa[ord(inp[0][i])-65]=index1 if inp[1][index1]==inp[0][i] else index2
                fila.append(inp[0][i])
                break
            print(fila.pop(),end='')
    fila.reverse()
    print(''.join(fila))
    fila.clear()