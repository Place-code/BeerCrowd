repetion,calls=[0]*40,[0]*40
repetion[0],calls[0]=0,1
repetion[1],calls[1]=1,1
for i in range(2,39):
    repetion[i]=repetion[i-1]+repetion[i-2]
    calls[i]=calls[i-1]+calls[i-2]+1
for i in range(int(input())):
    x=int(input())
    print('fib({}) = {} calls = {}'.format(x,calls[x]-1,repetion[x]))
