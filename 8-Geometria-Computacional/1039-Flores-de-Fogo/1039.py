while (1):
    try:
        r1, c1x, c1y, r2, c2x, c2y = map(int, input().split())
        print("RICO") if ((c1x-c2x)*(c1x-c2x) + (c1y-c2y)*(c1y-c2y))**0.5 + r2 <= r1 else print ("MORTO")
    except EOFError:
        break