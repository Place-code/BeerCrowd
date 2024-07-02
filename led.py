for _ in range(int(input())):
    n = input()
    n = [int(i) for i in n]
    cont = 0
    for i in n:
        if i == 1:
            cont += 2
        elif i == 2 or i == 3 or i == 5:
            cont += 5
        elif i == 4:
            cont += 4
        elif i == 6 or i == 9 or i == 0:
            cont += 6
        elif i == 7:
            cont += 3
        elif i == 8:
            cont += 7
    print (cont, "leds")