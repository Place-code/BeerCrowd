for i in range(int(input())):
    r = []
    r.append(input())
    ms = int(input())
    for i in r:
        r = [_ for _ in i]
    asc = []
    for i in r:
        if str(chr(ord(i) - ms)).isalpha() == False:
            asc.append(chr(((ord(i) + 26) - ms)))
        else:
            asc.append(chr(ord(i) - ms))
    cript = ''
    for i in asc:
        cript += i
    print (cript)