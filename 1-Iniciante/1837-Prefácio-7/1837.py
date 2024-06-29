sbdc=input().split(" ")
a=int(sbdc[0])
b=int(sbdc[1])

q = a // b
r = a % b

if r < 0 and b > 0:
    r += b
    q -= 1
elif r < 0 and b < 0:
    r -= b
    q += 1

print(q, r)