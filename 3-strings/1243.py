def isAWord(string):
    if string[0]=='.':return 0
    dif=0
    for i in string:
        if i=='.' and string.index('.')==len(string)-1:dif=1;break
        if (ord(i)<65 or ord(i)>90) and (ord(i)<97 or ord(i)>122):return 0
    return len(string)-dif
while 1:
    try:
        totStrings,average=0,0
        for _ in list(map(isAWord,input().split())):
            average+=_
            totStrings+=1 if _ else 0
        if not totStrings or not average:print('250');continue
        result=average//totStrings
        print('250')if result<4 else print('500') if result<6 else print('1000')
    except EOFError:break
