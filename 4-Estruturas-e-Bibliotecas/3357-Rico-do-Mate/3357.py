people, bottle, bowl = input().split()
people, bottle, bowl = int(people), float(bottle), float(bowl)
contestants = input().split()
dose = 1
while bottle - bowl*dose > 0:
    dose += 1
dose -= 1
print (contestants[dose%people], round((bottle-bowl*(dose)), 1))