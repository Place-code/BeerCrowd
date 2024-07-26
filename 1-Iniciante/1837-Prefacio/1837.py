a = input().split()
if int(a[1]) < 0:
    print ((int(a[0])) // (int(a[1]) * - 1) * - 1, int(a[0]) % (int(a[1]) * -1))
else:
    print (int(a[0]) // int(a[1]), int(a[0]) % int(a[1]))