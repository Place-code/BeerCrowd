while True:
    d, n = input().split()
    if d == '0' and n == '0':
        break
    n = [int(i) for i in n]
    while int(d) in n:
        n.remove(int(d))
    if sum(n) == 0:
        print (0)
    else:
        num = ''
        for i in n:
            num += str(i)
        print (int(num))