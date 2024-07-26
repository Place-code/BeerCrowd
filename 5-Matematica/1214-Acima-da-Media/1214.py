for _ in range (int(input())):
    notas = input().split()
    notas = [int(i) for i in notas]
    notas.pop(0)
    media = sum(notas)/len(notas)
    cont = 0
    for i in notas:
        if i > media:
            cont += 1
    cont = cont/len(notas) * 100
    cont = ("%.3f" % cont)
    print ("{}{}". format(cont,"%"))