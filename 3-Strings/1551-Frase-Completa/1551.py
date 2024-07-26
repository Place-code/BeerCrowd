for _ in range(int(input())):
    alpha = {}
    txt = input()
    txt = [i for i in txt]
    for i in txt:
        if i.isalpha() == True:
            alpha.update({i : 0})
    if len(alpha) < 13:
        print ("frase mal elaborada")
    elif len(alpha) >= 13 and len(alpha) < 26:
        print ("frase quase completa")
    else:
        print ("frase completa")