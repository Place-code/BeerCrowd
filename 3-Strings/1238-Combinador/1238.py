for _ in range (int(input())):
    st1, st2 = input().split()
    st1 = [i for i in st1]
    st2 = [i for i in st2]
    while True:
        if len(st1) != 0:
            for i in st1:
                if len(st1) == 1 and len(st2) == 0:
                    print (i)
                elif len(st1) >= 1 and len(st2) >= 0:
                    print (i, end='')
                st1.remove(i)
                break
        if len(st2) != 0:
            for q in st2:
                if len(st2) == 1 and len(st1) == 0:
                    print (q)
                elif len(st2) >= 1 and len(st1) >= 0:
                    print (q, end='')
                st2.remove(q)
                break
        if len(st1) == 0 and len(st2) == 0:
            break