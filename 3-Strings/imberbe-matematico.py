a = int(input())
nums = input().split()
primos = []
for _ in nums:
    _ = int(_)
    if _ != 1:
        for i in range (2, round(_ ** 0.5) + 2):
            fat = i
            if _ % i == 0:
                break
        if _ % fat != 0 or _ == 2 or _ == 3:
            primos.append(_)
for _ in primos:
    fat = 0
    analog = _
    for i in range (analog - 1, 0, - 1):
        fat = _ * i
        _ = fat
    print ('{}!' .format(analog), '=', fat)