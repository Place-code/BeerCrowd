while True:
    try:
        txt = input()
        txt = [i for i in txt]
        string = ''
        cont = -1
        for i in txt:
            if i != ' ':
                cont += 1
            if cont % 2 == 0:
                string += i.upper()
            else:
                string += i.lower()
        print (string)
    except EOFError:
        break