x, y = input().split()
y = int(y)
x = int(x)
z = []
for _ in range (1, y + 1):
    z.append(_)
for _ in z:
    if _ % x == 0:
        print (_)
    else:
        print (_,"",end='')