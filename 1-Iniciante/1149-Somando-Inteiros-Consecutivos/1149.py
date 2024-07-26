x = input().split()
a = 0
n = 0
for _ in x:
    _ = int(_)
    if a == 0:
        if _ > 0:
            a = _
    else:
        n = _
a = int(a)
n = int(n)
l = []
x = a
for _ in range (0, n):
    a = x + _
    l.append(a)
print (sum(l))