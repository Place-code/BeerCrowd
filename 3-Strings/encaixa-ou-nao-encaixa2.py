for _ in range(int(input())):
    a, b = input().split()
    a = [int(i) for i in a]
    b = [int(i) for i in b]
    if len(a) >= len(b):
        while len(a) != len(b):
            a.remove(a[0])
        if a == b:
            print ("encaixa")
        else:
            print ("nao encaixa")
    else:
        print ("nao encaixa")