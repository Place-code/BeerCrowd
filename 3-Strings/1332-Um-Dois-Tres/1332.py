def analise(a):
    if len(a) == 5:
        print (3)
    elif a[0] == 't' and a[1] == 'w' or a[0] == 't' and a[2] == 'o' or a[1] == 'w' and a[2] == 'o':
        print (2)
    else:
        print (1)
nums = []
for i in range (int(input())):
    nums.append(input())
for i in nums:
    i = [_ for _ in i]
    analise(i)