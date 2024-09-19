d = int(input(""))

y = 0
m = 0

if (d >= 30):
    m = int(d / 30)
    d = d % 30
    
    if (m >= 12):
        y = int(m / 12)
        m = m % 12

print(f"{y} ano(s)\n{m} mes(es)\n{d} dia(s)")