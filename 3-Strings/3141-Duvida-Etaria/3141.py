name = input()
now = input().split('/')
birth = input().split('/')
dates = {}
cont = 0
for _ in now:
    dates.update({cont : int(_)})
    cont += 1
for _ in birth:
    dates.update({cont : int(_)})
    cont += 1
if dates[0] == dates[3] and dates[1] == dates[4]:
    print ("Feliz aniversario!")
if dates[1] > dates[4]:
    print ("Voce tem", (dates[2] - dates[5]), "anos {}." .format(name))
elif dates[1] < dates[4]:
    print ("Voce tem", (dates[2] - dates[5]) - 1, "anos {}." .format(name))
elif dates[1] == dates[4] and dates[0] < dates[3]:
    print ("Voce tem", (dates[2] - dates[5]) - 1, "anos {}." .format(name))
elif dates[1] == dates[4] and dates[0] == dates[3]:
    print ("Voce tem", (dates[2] - dates[5]), "anos {}." .format(name))