def flavious(n, k):
    ans, i = 0, 1
    while i <= n:
        ans = (ans + k) % i
        i += 1
    return ans+1
for i in range(1, int(input()) + 1):
    n, k = map(int, input().split())
    print (f"Case {i}: {flavious(n, k)}")