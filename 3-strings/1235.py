for i in range(int(input())):
    x=input()
    aux=None
    tam=len(x)-1
    for i in range(tam+1):
        aux=x[int(tam/2)-i] if i<int(tam/2)+1 else x[tam-(i-int(tam/2)-1)]
        print(aux,end='')
    print()