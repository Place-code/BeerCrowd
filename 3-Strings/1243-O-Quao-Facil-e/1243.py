while True:
    try:
        txt = input().split(' ')
        while '' in txt:
            txt.remove('')
        index = []
        words = []
        cont = 0
        for i in txt:
            for _ in i:
                if _.isalpha() == False and i.count(_) > 1:
                    index.append(i)
                    break
                elif _.isalpha() == False and i[-1] != '.':
                    index.append(i)
                    break
                elif _.isalpha() == False and _ == '.':
                    cont += 1
        for i in index:
            txt.remove(i)
        for i in txt:
            words.append(len(i))
        words = sum(words)
        words -= cont
        if len(txt) > 0:
            if words // len(txt) <= 3:
                print (250)
            elif words // len(txt) == 4 or words // len(txt) == 5:
                print (500)
            elif words // len(txt) >= 6:
                print (1000)
        else:
            print (250)
    except EOFError:
        break