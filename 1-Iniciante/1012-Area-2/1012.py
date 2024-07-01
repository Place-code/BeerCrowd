x=input().split(' ')
a=float(x[0])
b=float(x[1])
c=float(x[2])
print(f"""TRIANGULO: {(a*c)/2:.3f}
CIRCULO: { 3.14159*c**2:.3f}
TRAPEZIO: {((a+b)*c)/2:.3f}
QUADRADO: {b*b:.3f}
RETANGULO: {a*b:.3f}""")