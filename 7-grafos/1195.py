class Nodo():
    def __init__(self,v):
        self.valor=v    
        self.ld=None
        self.le=None
def insert(nu,comp):
    if nu==None:
        return Nodo(comp)
    if comp<nu.valor:
        nu.le=insert(nu.le,comp)
    else:
        nu.ld=insert(nu.ld,comp)
    return nu

def pre(nu):
    if nu:
        array.append(str(nu.valor))
        pre(nu.le)
        pre(nu.ld)
def infx(nu):
    if nu:
        infx(nu.le)
        array.append(str(nu.valor))
        infx(nu.ld)
def pos(nu):
    if nu:
        pos(nu.le)
        pos(nu.ld)
        array.append(str(nu.valor))

for i in range(int(input())):
    z=int(input())
    x=list(map(int,input().split()))
    novo=Nodo(x[0])
    for j in x[1:z]:
        novo=insert(novo,j)
    print('Case {}:'.format(i+1))
    array=[]
    pre(novo)
    print('Pre.:',end=' ')
    print(' '.join(array))
    array.clear()
    infx(novo)
    print('In..:',end=' ')
    print(' '.join(array))
    array.clear()
    pos(novo)
    print('Post:',end=' ')
    print(' '.join(array))
    print()