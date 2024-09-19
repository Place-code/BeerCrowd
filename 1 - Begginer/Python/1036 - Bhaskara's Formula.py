A = input().split()
a, b, c = float(A[0]), float(A[1]), float(A[2])

D = b**2 - 4*a*c

if (D <= 0):
    print("Impossivel calcular")

else:
    a_2 = a * 2
    
    if (a_2 == 0):
        print("Impossivel calcular")
        
    else:
        X1 = (-b + D ** 0.5) / a_2
        X2 = (-b - D ** 0.5) / a_2
        
        print(f"R1 = {X1:.5f}")
        print(f"R2 = {X2:.5f}")