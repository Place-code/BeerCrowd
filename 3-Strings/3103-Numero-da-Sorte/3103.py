for i in range(int(input())):
    txt = list(map(int, input().replace('\r','')))
    zcount = txt.count(0)
    txt = sorted(i for i in txt if i != 0)
    for i in range (zcount):
        txt.insert(1, 0)
    print (''.join(map(str, txt)))