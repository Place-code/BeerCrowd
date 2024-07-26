for _ in range(int(input())):
    txt = input()
    txt = txt.split(' ')
    while ' ' in txt:
        txt.remove(' ')
    string = ''
    for i in txt:
        for q in i:
            string += q
            break
    print (string)