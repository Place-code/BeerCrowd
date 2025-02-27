while (1):
    nbanks, nfare = map(int, input().split())
    if nbanks == nfare == 0:
        break
    credit = input().split()
    banks = [int(i) for i in credit]
    for i in range (nfare):
        d, c, v = map(int, input().split())
        banks[d-1] -= v
        banks[c-1] += v
    able = True
    for i in banks:
        if i < 0:
            able = False
            break
    print ("S") if able else print ("N")