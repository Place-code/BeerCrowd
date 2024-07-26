pares = []
impares = []
for _ in range (int(input())):
    n = int(input())
    if n % 2 == 0:
        pares.append(n)
    else:
        impares.append(n)
pares.sort()
impares.sort()
impares.reverse()
for _ in pares:
    print (_)
for _ in impares:
    print (_)