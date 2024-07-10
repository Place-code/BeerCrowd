for i in range (int(input())):
    preco = {}
    uni = {}
    for _ in range (int(input())):
        a, b = input().split()
        preco.update({a : float(b)})
    for _ in range (int(input())):
        a, b = input().split()
        uni.update({a : float(b)})
    quer = {}
    for _ in uni:
        quer.update({_ : preco[_] * uni[_]})
    total = 0
    for _ in quer:
        total += quer[_]
    print ("R$ {:.2f}" .format(total))