for i in range(int(input())):
    txt = input()
    txt = [_ for _ in txt]
    let = {' ': '0', 'a' : '2', 'b' : '2' * 2, 'c' : '2' * 3, 'd' : '3', 'e' : '3' * 2, 'f' : '3' * 3, 'g' : '4', 'h': '4' * 2, 'i': '4' * 3, 'j': '5', 'k': '5' * 2, 'l': '5' * 3, 'm': '6', 'n': '6' * 2, 'o': '6' * 3, 'p': '7', 'q': '7' * 2, 'r': '7' * 3, 's': '7' * 4, 't': '8', 'u': '8' * 2, 'v': '8' * 3, 'w': '9', 'x': '9' * 2, 'y': '9' * 3, 'z': '9' * 4}
    stg = ''
    ant = ''
    now = ''
    pri = 0
    for _ in txt:
        if _.isupper() == True:
            stg += '#'
            _ = _.lower()
            pri = 1
        now = let[_]
        for i in now:
            now = i
            break
        if now == ant and pri != 1:
            stg += '*'
        stg += let[_]
        ant = let[_]
        for i in ant:
            ant = i
            break
        pri = 0
    print (stg)