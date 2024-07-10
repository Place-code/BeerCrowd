names = []
for _ in range (int(input())):
    names.append(input())
for _ in names:
    cont = 0
    for i in _:
        i = i.lower()
        if i != 'a' and i != 'e' and i != 'i' and i != 'o' and i != 'u':
            cont += 1 
        if cont == 3:
            print (_, 'nao eh facil')
            break
        if i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u':
            cont = 0
    if cont != 3:
        print (_, 'eh facil')