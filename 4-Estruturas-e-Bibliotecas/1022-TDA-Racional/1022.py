def mdc(n1, d1):
    divcom = 1
    if n1 < d1 and n1 != 0:
        for i in range (abs(n1), 1, -1):
            if n1 % i == 0 and d1 % i == 0:
                divcom = i
                break
    else:
        for i in range (abs(d1), 1, -1):
            if n1 % i == 0 and d1 % i == 0:
                divcom = i
                break
    print ("{}/{} = {}/{}" .format(n1, d1, n1//divcom, d1//divcom))

for i in range(int(input())):
    express = input().split()
    n1, d1, n2, d2 = int(express[0]), int(express[2]), int(express[4]), int(express[6])
    match express[3]:
        case '+':
            mdc((n1*d2+n2*d1), (d1*d2))
        case '-':
            mdc((n1*d2-n2*d1), (d1*d2))
        case '*':
            mdc((n1*n2), (d1*d2))
        case '/':
            mdc((n1*d2), (n2*d1))