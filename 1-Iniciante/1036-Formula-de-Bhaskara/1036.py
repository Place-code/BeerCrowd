a, b, c = input().split()
a = float(a); b = float(b); c = float(c)
if a <= 0 or b * b - 4 * a * c < 0:
    print ("Impossivel calcular")
else:
    print ("R1 = {:.5f}" .format((- b + ((b * b - 4 * a * c) ** 0.5)) / (2 * a)))
    print ("R2 = {:.5f}" .format((- b - ((b * b - 4 * a * c) ** 0.5)) / (2 * a)))