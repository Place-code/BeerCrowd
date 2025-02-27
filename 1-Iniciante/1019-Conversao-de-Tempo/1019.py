n = int(input())
h = 0
min = 0
if n > 60:
    min += n // 60
    n -= (n // 60) * 60
if min > 60:
    h += min // 60
    min -= (min // 60) * 60
print ("{}:{}:{}".format(h, min, n))