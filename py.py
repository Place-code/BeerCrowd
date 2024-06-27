r = []
for i in range(int(input())):
    r.append(input())
    ms = int(input())
    for i in r:
        r = [_ for _ in i]
    asc = []
    for i in r:
        if ord(i) < 75:
            asc.append(chr(((ord(i) + 25) - (ms - 1))))
        else:
            asc.append(chr(ord(i) - ms))
    for i in asc:
        if i == r[-1]:
            print (i)
        else:
            print (i, end='')
            