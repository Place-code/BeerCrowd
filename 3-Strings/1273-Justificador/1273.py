times = 0
while True:
    times += 1
    words = []
    spaces = []
    a = int(input())
    if a == 0:
        break
    if times != 1:
        print ()
    for _ in range (a):
        b = input()
        words.append(b)
        spaces.append(len(b))
    cont = 0
    big = max(spaces)
    for _ in words:
        for i in spaces:
            for cont in range (big - len(_)):
                print (" ", end='')
            spaces.remove(i)
            break
        print (_)