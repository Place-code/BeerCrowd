while True:
    try:
        txt = input()
        txt = [i for i in txt]
        analog = ''
        chars = {}
        for i in txt:
            if i == '*' or i == '_':
                if i in chars:
                    chars.update({i : chars[i] + 1})
                else:
                    chars.update({i : 1})
                if chars[i] % 2 != 0:
                    if i == '_':
                        analog += '<i>' 
                    else:
                        analog += '<b>'
                else:
                    if i == '_':
                        analog += '</i>' 
                    else:
                        analog += '</b>'
            else:
                analog += (i)
        print (analog)
    except EOFError:
        break