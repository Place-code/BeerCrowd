for _ in range(int(input())):
    string = ''
    txt = input()
    txt = [i for i in txt]
    txt.reverse()
    index = 0
    for i in txt:
        index += 1
        if index > len(txt) // 2:
            string += i
    index = 0
    for i in txt:
        index += 1
        if index > len(txt) // 2:
            break
        string += i
    print (string)