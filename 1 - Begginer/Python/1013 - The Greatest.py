a, b, c = map(int, input().split())

ab = (a + b + abs(a-b)) / 2
m = (ab + c + abs(ab-c)) / 2

m = int(m)

print(f"{m} eh o maior")