ncities, nfrontiers = input().split()
ncities, nfrontiers = int(ncities), int(nfrontiers)
cities = [False] * ncities
qnt = 0
for i in range (nfrontiers):
    c1, c2 = input().split()
    c1, c2 = int(c1), int(c2)
    if not cities[c1-1] and not cities[c2-1]:
        qnt += 1
    cities[c1-1], cities[c2-1] = True, True
print (qnt + cities.count(False))