for i in range(int(input())):
    txt = []
    txt.append(input())
    txt = [_ for _ in txt[0]]
    asc = []
    cont = 0
    for i in txt:
        cont += 1
        if i.isalpha() == True and cont <= len(txt) // 2 + 1 and len(txt) % 2 != 0:
            asc.append(chr(ord(i) + 2))
        elif i.isalpha() == True and cont <= len(txt) // 2 and len(txt) % 2 == 0:
            asc.append(chr(ord(i) + 2))
        elif i.isalpha() == False and cont <= len(txt) // 2 and len(txt) % 2 == 0:
            asc.append(chr(ord(i) - 1))
        elif i.isalpha() == False and cont <= len(txt) // 2 + 1 and len(txt) % 2 != 0:
            asc.append(chr(ord(i) - 1))
        elif i.isalpha() == False:
            asc.append(chr(ord(i)))
        else:
            asc.append(chr(ord(i) + 3))
    asc.reverse()
    cript = ''
    for i in asc:
        cript += i
    print (cript)