[ih, im, fh, fm] = list(map(int, input().split()))

H = fh - ih
M = fm - im

if (M < 0):
    H = H - 1
    M = M + 60

if (H == 0 and M == 0):
    H = 24
    M = 0

if (H < 0):
    H*=-1
    H = 24 - H

print(f"O JOGO DUROU {H} HORA(S) E {M} MINUTO(S)")