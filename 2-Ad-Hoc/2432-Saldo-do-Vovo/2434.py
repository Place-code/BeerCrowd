r = input().split()
r[1] = int(r[1])
money = []
for i in range(int(r[0])):
    r[1] += int(input())
    money.append(r[1])
print (min(money))