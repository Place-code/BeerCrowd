pi = 3.14159

def read_line():
    return [float(x) for x in input().split()]

ABC = read_line()

t_3 = ABC[0] * ABC[2] / 2
c = pi * ABC[2] ** 2
t_4 = (ABC[0] + ABC[1]) * ABC[2] / 2
s = ABC[1] ** 2
r = ABC[0] * ABC[1]

print(f"TRIANGULO: {t_3:.3f}\nCIRCULO: {c:.3f}\nTRAPEZIO: {t_4:.3f}\nQUADRADO: {s:.3f}\nRETANGULO: {r:.3f}")