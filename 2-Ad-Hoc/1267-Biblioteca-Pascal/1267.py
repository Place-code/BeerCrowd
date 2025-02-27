while True:
    width, height = input().split()
    width, height = int(width), int(height)
    if width == height == 0:
        break
    matriz = []
    for i in range(height):
        matriz.append(input().split())
    filled, isfilled = 0, False
    for column in range(width):
        filled = 0
        for row in matriz:
            if row[column] == '1':
                filled += 1
            else:
                break
        if filled == height:
            isfilled = True
            break
    print ("yes") if isfilled else print ("no")