for i in range(int(input())):
    qt = 0
    num = float(input())
    while num > 1:
        num -= num/2
        qt += 1
    print (qt, "dias")