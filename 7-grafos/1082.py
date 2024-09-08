for r in range(int(input())):
    dici={}
    alfa=[]
    x=list(map(int,input().split()))
    cont=0
    for i in range(x[0]):
        dici[chr(97+i)]=[]
        alfa.append(chr(97+i))
    for i in range(x[1]):
        [e1,e2]=input().split()
        dici[e1].append(e2)
        dici[e2].append(e1)
    print('Case #{}:'.format(r+1))
    while len(alfa)>0:
        fila=[alfa[0]]
        prin=[]
        alfa.pop(0)
        while len(fila)>0:
            for i in dici[fila[0]]:
                if i in alfa:
                    fila.append(i)
                    alfa.remove(i)
            prin.append(fila[0])
            fila.pop(0)
        prin.sort()
        for i in prin:
            print(i,end=',')
        print()
        cont+=1
    print('{} connected components\n'.format(cont))