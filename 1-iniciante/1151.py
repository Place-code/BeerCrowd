fib=[0,1]
x=int(input())
for i in range(x):
    if(i!=x-1): print(fib[0], end=' ')
    else: print(fib[0])
    fib[1]+=fib[0]
    fib[0]=fib[1]-fib[0]