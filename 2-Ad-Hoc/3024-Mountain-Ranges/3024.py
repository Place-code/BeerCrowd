points, quota = input().split()
points, quota = int(points), int(quota)
dots = list(map(int, input().split()))
cnt, index = [0]*points, 0
ant = dots[0]
onsequence = False
for i in range (1, points):
    curr = dots[i]
    if curr - ant <= quota:
        onsequence = True
    else:
        onsequence = False
        index += 1
    if (onsequence):
        cnt[index] += 1
    ant = curr
print (max(cnt)+1)