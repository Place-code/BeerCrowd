for i in range(int(input())):
    [tam,pre,infx]=input().split()
    tam=int(tam)
    array=[0 for i in range(52)]
    andados=array.copy()
    sub=None
    for i in range(tam):
        sub=65 if ord(infx[i])<91 else 72
        array[ord(infx[i])-sub]=i
    fila=[pre[0]]
    tam-=1
    for j in pre[1:]:
        while True:
            # print(fila)
            ond=None
            sub=65 if ord(fila[-1])<91 else 72
            ond=array[ord(fila[-1])-sub]
            asc=[0,0]
            index1,index2=ond,ond
            for k in range(tam):
                if asc[0]==1 and asc[1]==1:
                    break
                index1-=1 if index1>0 and asc[0]!=1 else 0
                index2+=1 if index2<tam and asc[1]!=1 else 0
                # print(index1,index2)
                # 
                sub=65 if ord(infx[index1])<91 else 72
                asc[0]=andados[ord(infx[index1])-sub]
                sub=65 if ord(infx[index2])<91 else 72
                asc[1]=andados[ord(infx[index2])-sub]
                #
                asc[0]=1 if index1<1 else asc[0]
                asc[1]=1 if index2>tam-1 else asc[1]
                if infx[index1]==j or infx[index2]==j:
                    break
            if infx[index1]==j or infx[index2]==j:
                sub=65 if ord(fila[-1])<91 else 72
                andados[ord(fila[-1])-sub]=1
                fila.append(j)
                break
            print(fila.pop(),end='')
    fila.reverse()
    print("".join(fila))
    fila.clear()