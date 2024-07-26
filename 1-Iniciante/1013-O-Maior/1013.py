a, b, c = input().split()
a = int(a)
b = int(b)
c = int(c)
if (a + b + abs(a - b)) / 2 > c:
    print (int((a + b + abs(a - b)) / 2), "eh o maior")
else:
    print (c, "eh o maior")