while True:
    h = input().split()
    if h[0] == '0' and h[1] == '0' and h[2] == '0' and h[3] == '0':
        break
    if h[0] == '0':
        h[0] = '24'
    if h[2] == '0':
        h[2]  = '24'
    h = [int(i) for i in h]
    if h[0] < h[2] or h[0] == h[2] and h[1] <= h[3]:
        print (int((h[2] * 60 + h[3]) - (h[0] * 60 + h[1])))
    else:
        print (int((h[2] * 60 + 24 * 60 + h[3]) - (h[0] * 60 + h[1])))