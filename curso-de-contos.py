# Tentado
while True:
    try:
        n, l, c = input().split()
        l = int(l)
        c = int(c)
        txt = input()
        print (int((len(txt) / c) / l) + 1)
    except EOFError:
        break