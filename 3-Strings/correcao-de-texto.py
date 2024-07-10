while True:
    try:
        txt = input()
        txt = [i for i in txt]
        stg = ''
        for _ in txt:
            if _ == '@':
               stg += 'a'
            elif _ == '&':
                stg += 'e'
            elif _ == '!':
                stg += 'i'
            elif _ == '*':
                stg += 'o'
            elif _ == '#':
                stg += 'u'
            else:
                stg += _
        print (stg)
    except EOFError:
        break