a = 1
b = []
while a != 0:
    a = int(input())
    if a == 0:
        break
    b.append(a)
for _ in b:
    for a in range (1, _ + 1):
        if a == _:
            print (a)
        else:
            print (a, "", end='')