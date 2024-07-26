for _ in range(int(input())):
    a = input().split()
    a = [int(i) for i in a]
    a.sort()
    if a[1] % a[0] == 0:
        print (a[0])
    else:
        n1 = a[1]
        n2 = a[0]
        resto = n1 % n2
        while resto != 0:
            n1 = n2
            n2 = resto
            resto = n1 % n2
        print (n2)