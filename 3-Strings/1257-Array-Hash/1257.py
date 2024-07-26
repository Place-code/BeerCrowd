for _ in range (int(input())):
    string = []
    for i in range (int(input())):
        string.append(input())
    nums = 0
    index = -1
    for i in string:
        index += 1
        cont = -1
        for _ in i:
            cont += 1
            nums += (ord(_) - 65) + index + cont
    print (nums)