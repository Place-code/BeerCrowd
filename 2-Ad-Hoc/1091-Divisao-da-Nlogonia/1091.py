while True:
    cases = int(input())
    if cases == 0:
        break
    dx, dy = input().split()
    dx, dy = int(dx), int(dy)
    for _ in range (cases):
        hx, hy = input().split()
        hx, hy = int(hx), int(hy)
        if hx == dx or hy == dy:
            print("divisa")
        else:
            if hx > dx:
                if hy > dy:
                    print("NE")
                else:
                    print("SE")
            else:
                if hy > dy:
                    print("NO")
                else:
                    print("SO")