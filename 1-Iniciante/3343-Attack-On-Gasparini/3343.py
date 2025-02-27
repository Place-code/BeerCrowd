n, x = input().split()
x = int(x)
attacks = []
for i in input():
    if i == 'P':
        attacks.append(0)
    elif i == 'M':
        attacks.append(1)
    else:
        attacks.append(2)
damage = [int(i) for i in input().split()]
indexes = [0, 0, 0]
walls = [x]
for attack in attacks:
    hit = damage[attack]
    while walls[indexes[attack]] < hit:
        indexes[attack] += 1
        if indexes[attack] == len(walls):
            walls.append(x)
    walls[indexes[attack]] -= hit
print (len(walls))