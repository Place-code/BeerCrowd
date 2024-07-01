for i in range(int(input())):
    xs=input().split(" ")
    x=xs[0]
    y=xs[1]
    if len(x)>=len(y):
        x=x[len(x)-len(y):]
        if x == y:
            print("encaixa")
        else:
            print("nao encaixa")
    else:
        print("nao encaixa")