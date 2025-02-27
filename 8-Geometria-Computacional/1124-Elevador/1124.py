while (1):
    width, height, r1, r2 = map(int, input().split())
    if width == height == r1 == r2 == 0:
        break
    print ("S") if r1*2 <= width and r2*2 <= width and r1*2 <= height and r2*2 <= height and ((height-r1-r2)**2+(width-r1-r2)**2)**0.5 >= r1+r2 else print ("N")