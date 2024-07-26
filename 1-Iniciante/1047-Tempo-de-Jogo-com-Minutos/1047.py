time = {}
x = input().split()
for i, _ in enumerate(x):
    time.update({i : int(_)})
if time[1] > time[3]:
    time[2] -= 1
    time[3] += 60
if time[0] < time[2] or time[0] == time[2] and time[1] < time[3]:
    print ("O JOGO DUROU", time[2] - time[0], "HORA(S) E", time[3] - time[1], "MINUTO(S)")
else:
    print ("O JOGO DUROU", time[2] - time[0] + 24, "HORA(S) E", time[3] - time[1], "MINUTO(S)")