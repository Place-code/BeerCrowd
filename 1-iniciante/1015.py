x=[input().split() for x in range(2)]
print(f"{((((float(x[1][0])-float(x[0][0]))**2)+((float(x[1][1])-float(x[0][1]))**2))**0.5):.4f}")