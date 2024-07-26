din = {100 : 0, 50: 0, 20: 0, 10: 0, 5: 0, 2: 0, 1:0, 0.5: 0, 0.25: 0, 0.1: 0, 0.05: 0, 0.01: 0}
n = float(input())
if n >= 100:
    din[100] = int(n // 100)
    n -= 100 * (n // 100)
    n = round (n, 2)
if n >= 50:
    din[50] = int(n // 50)
    n -= 50 * (n // 50)
    n = round (n, 2)
if n >= 20:
    din[20] = int(n // 20)
    n -= 20 * (n // 20)
    n = round (n, 2)
if n >= 10:
    din[10] = int(n // 10)
    n -= 10 * (n // 10)
    n = round (n, 2)
if n >= 5:
    din[5] = int(n // 5)
    n -= 5 * (n // 5)
    n = round (n, 2)
if n >= 2:
    din[2] = int(n // 2)
    n -= 2 * (n // 2)
    n = round (n, 2)
if n >= 1:
    din[1] = int(n)
    n -= int(n)
    n = round (n, 2)
if n >= 0.5:
    din[0.5] = int(n / 0.5)
    n -= 0.5 * (n // 0.5)
    n = round (n, 2)
if n >= 0.25:
    din[0.25] = int(n / 0.25)
    n -= 0.25 * (n // 0.25)
    n = round (n, 2)
if n >= 0.1:
    din[0.1] = int(n / 0.1)
    n -= 0.1 * (n // 0.1)
    n = round (n, 2)
if n >= 0.05:
    din[0.05] = int(n / 0.05)
    n -= 0.05 * (n // 0.05)
    n = round (n, 2)
if n >= 0.01:
    din[0.01] = int(n / 0.01)
print ("NOTAS:")
print (din[100], "nota(s) de R$ 100.00")
print (din[50], "nota(s) de R$ 50.00")
print (din[20], "nota(s) de R$ 20.00")
print (din[10], "nota(s) de R$ 10.00")
print (din[5], "nota(s) de R$ 5.00")
print (din[2], "nota(s) de R$ 2.00")
print ("MOEDAS:")
print (din[1], "moeda(s) de R$ 1.00")
print (din[0.5], "moeda(s) de R$ 0.50")
print (din[0.25], "moeda(s) de R$ 0.25")
print (din[0.1], "moeda(s) de R$ 0.10")
print (din[0.05], "moeda(s) de R$ 0.05")
print (din[0.01], "moeda(s) de R$ 0.01")