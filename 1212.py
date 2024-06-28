while True:
    for i in range(int(input())):
        def f(x):
            if x<3: return 1
            return f(x-1)+f(x-2)
        y=f(int(input(),2))
        print('0'*(3-len(list(str(y))))+str(y))
#Tentei e não deu ;-;