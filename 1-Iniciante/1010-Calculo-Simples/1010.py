valor = []
for _ in range (2):
    cod, qt, num = input().split()
    valor.append(int(qt))
    valor.append(float(num))
print ("VALOR A PAGAR: R$ {:.2f}" .format(valor[0] * valor[1] + valor[-2] * valor[-1]))