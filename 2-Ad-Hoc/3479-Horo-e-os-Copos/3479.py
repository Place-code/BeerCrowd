months = ["capricornio", "aquario", "peixes", "aries", "touro", "gemeos", "cancer", "leao", "virgem", "libra", "escorpiao", "sagitario"]
data = input().split("/")
data[0], data[1] = int(data[0]), int(data[1])
if (data[1] >= 3 and data[1] <= 6):
    print (months[data[1] - 1]) if data[0] <= 20 else print (months[data[1]])
if data[1] >= 7 and data[1] <= 10:
    print (months[data[1] - 1]) if data[0] <= 22 else print (months[data[1]])
if data[1] >= 11 and data[1] <= 12:
    print (months[data[1] - 1]) if data[0] <= 21 else print (months[0])
if data[1] == 1:
    print (months[data[1] - 1]) if data[0] <= 19 else print (months[data[1]])
if data[1] == 2:
    print (months[data[1] - 1]) if data[0] <= 18 else print (months[data[1]])