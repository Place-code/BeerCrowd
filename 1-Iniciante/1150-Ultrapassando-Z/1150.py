x = int(input())
z = int(input())
l = []
while z <= x:
    z = int(input())
_ = x + 1
l.append(x)
l.append(_)
while sum(l) < z:
    _ += 1
    l.append(_)
print (len(l))