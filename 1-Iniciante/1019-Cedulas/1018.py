n = int(input())
analog = n
ceds = {'100': 0, '50': 0, '20': 0, '10': 0, '5': 0, '2': 0, '1': 0}
if n >= 100:
    ceds['100'] = n // 100
    n -= 100 * (n // 100)
if n >= 50:
    ceds['50'] = n // 50
    n -= 50 * (n // 50)
if n >= 20:
    ceds['20'] = n // 20
    n -= 20 * (n // 20)
if n >= 10:
    ceds['10'] = n // 20
    n -= 10 * (n // 10)
if n >= 5:
    ceds['5'] = n // 5
    n -= 5 * (n // 5)
if n >= 2:
    ceds['2'] = n // 2
    n -= 2 * (n // 2)
if n >= 1:
    ceds['1'] = n
print (analog)
print (ceds['100'], "nota(s) de R$ 100,00")
print (ceds['50'], "nota(s) de R$ 50,00")
print (ceds['20'], "nota(s) de R$ 20,00")
print (ceds['10'], "nota(s) de R$ 10,00")
print (ceds['5'], "nota(s) de R$ 5,00")
print (ceds['2'], "nota(s) de R$ 2,00")
print (ceds['1'], "nota(s) de R$ 1,00")