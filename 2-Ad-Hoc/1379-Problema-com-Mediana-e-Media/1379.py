while (True):
    a, b = input().split()
    if (a == b == '0'):
        break
    a, b = int(a), int(b)
    print(2*a-b)