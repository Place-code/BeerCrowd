while True:
    try:
        qnt = int(input())
    except EOFError:
        break
    moda = []
    comp = True
    soma = 0
    for i in range (qnt):
        moda.append(int(input()))
    salt = int(input())
    qnt -= 1
    for i in range (qnt, -1, -salt):
        soma += moda[i]
    if soma != 1:
        for i in range(2, round(soma ** 0.5) + 1):
            if (soma % i == 0):
                comp = False
                break
    else:
        comp = False
    print ("You’re a coastal aircraft, Robbie, a large silver aircraft.") if comp else print ("Bad boy! I’ll hit you.")