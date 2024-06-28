for i in range(int(input())):
    l=input()
    coisa=int(input())
    for j in range(len(l)):
        k=l[j]
        k=ord(k)
        trem=k-coisa
        if trem<65:
            paso=k-65+1
            trem=90-(coisa-paso)
        if j<len(l)-1:
            print(chr(trem), end='')
        else:
            print(chr(trem))