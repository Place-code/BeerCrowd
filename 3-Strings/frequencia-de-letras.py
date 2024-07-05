for _ in range (int(input())):
    chars = {}
    txt = input()
    txt = txt.lower()
    txt = [i for i in txt]
    for i in txt:
        if i.isalpha() == True:
            if i not in chars:
                chars.update({i : 1})
            else:
                chars.update({i : chars[i] + 1})
    strings = []
    for i in chars:
        if chars[i] == max(chars.values()):
            strings.append(i)
    strings.sort()
    most = ''
    for i in strings:
        most += i
    print (most)