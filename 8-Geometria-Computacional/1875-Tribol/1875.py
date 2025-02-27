def numerize(team):
    if team == 'R':
        return 0
    elif team == 'G':
        return 1
    else:
        return 2

pitch = [[2, 1], [0, 1], [1, 0]]
for i in range(int(input())):
    teams = [0, 0, 0]
    for j in range(int(input())):
        t1, t2 = input().split()
        t1 = numerize(t1)
        if pitch[t1][0] == numerize(t2):
            teams[t1] += 1
        else:
            teams[t1] += 2
    if (teams[0] == teams[1] == teams[2]):
        print ("trempate")
    else:
        Max = max(teams)
        if teams.count(Max) > 1:
            print ("empate")
        elif Max == teams[0]:
            print ("red")
        elif Max == teams[1]:
            print ("green")
        else:
            print ("blue")