while True:
    txt = input().split(' ')
    if txt[0] == "*":
        break
    cont = {}
    for _ in txt:
        for i in _:
            cont.update({i.lower() : 0})
            break
        if len(cont) > 1:
            break
    if len(cont) == 1:
        print ("Y")
    else:
        print ("N")