a = []
for i in range(5):
    a.append(int(input()))
b = {"par" : 0, "impar" : 0, "negativo" : 0, "positivo" : 0}
for i in a:
    if i % 2 == 0:
        b.update({"par" : b["par"] + 1})
    else:
        b.update({"impar" : b["impar"] + 1})
    if i > 0:
        b.update({"positivo" : b["positivo"] + 1})
    elif i < 0:
        b.update({"negativo" : b["negativo"] + 1})
print (b["par"], "valor(es) par(es)")
print (b["impar"], "valor(es) impar(es)")
print (b["positivo"], "valor(es) positivo(s)")
print (b["negativo"], "valor(es) negativo(s)")