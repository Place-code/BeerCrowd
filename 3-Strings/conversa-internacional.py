for _ in range(int(input())):
    nac = {}
    for i in range(int(input())):
        cnt = input()
        nac.update({cnt : 1})
    if len(nac) > 1:
        print ('ingles')
    else:
        print (cnt)