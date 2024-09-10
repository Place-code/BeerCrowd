# My 1th thought
#
# P1 = input().split()
# P2 = input().split()
# 
# P1 = (int(P1[0]), int(P1[1]), float(P1[2]))
# P2 = (int(P2[0]), int(P2[1]), float(P2[2]))

# ChatGPT help (I'll try do this without help in the next):
types = [int, int, float]

def read_line():
    return [t(x) for t, x in zip(types, input().split())]

P1 = read_line()
P2 = read_line()

V = P1[1] * P1[2] + P2 [1] * P2[2]

print(f"VALOR A PAGAR: R$ {V:.2f}")