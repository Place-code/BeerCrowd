while(x:=int(input())):
    array=[]
    cont,index,e,tot=0,0,0,0
    for i in input().split():
        tot+=int(cont/2) if index and i=="1" else 0
        cont += 1 if i=="0"else -cont
        index=e+1 if i=="1" else index
        e+=1
        array.append(i)
    cont=0
    for i in range(x+1):
        analysis=array[index+i] if i<x-index else array[i-x+index]
        if analysis=='1':break
        cont+=1
    tot+=cont/2
    print(int(tot))
