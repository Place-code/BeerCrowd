for i in range(int(input())):
    txt=input()
    valor=[]
    for j in txt:
        if j.isalpha():
            valor.append((ord(j)+3))
        else:
            valor.append(ord(j))
    valor.reverse()
    for j in range(0, len(valor),1):
        if(j>=int(len(valor)/2)):    
            valor[j]-=1
        if(j<len(valor)-1):
            print(chr(valor[j]), end='')
        else:
            print(chr(valor[j]))