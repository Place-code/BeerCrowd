# Incompleto
txt = input()
dnc = txt
txt = [str(i) for i in txt]
dnc = [str(i) for i in dnc]
while ' ' in dnc:
    dnc.remove(' ')
cont = 1
for i in dnc:
    cont += 1
    if cont % 2 == 0:
        txt[txt.index(i)] = txt[txt.index(i)].upper()
sent = ''
for i in txt:
    sent += i
print (sent)