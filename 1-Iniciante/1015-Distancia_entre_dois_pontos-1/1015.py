x=input().split(' ')
y=input().split(' ')
x1=float(x[0])
y1=float(x[1])

x2=float(y[0])
y2=float(y[1])

print(f"{((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))**0.5:.4f}")