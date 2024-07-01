x=[int(input()),int(input()),int(input()),int(input()),int(input())]
par=0
pos=0
neg=0
for i in x:
    if i%2==0:
        par+=1
    if i<0:
        neg+=1
    elif i>0:
        pos+=1
print(f"{par} valor(es) par(es)")
print(f"{len(x)-par} valor(es) impar(es)")
print(f"{pos} valor(es) positivo(s)")
print(f"{neg} valor(es) negativo(s)")