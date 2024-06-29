x=float(input())

notas=(100.00, 50.00, 20.00, 10.00, 5.00, 2.00, 1.00, 0.50, 0.25, 0.10, 0.05, 0.01)
print("NOTAS:")
comp="nota"
for i in notas:
    if i == 1.00:
        print("MOEDAS:")
        comp="moeda"
    if x >= i:
        print(f"{int(x//i)} {comp}(s) de R$ {i:.2f}")
        x=x-i*(x//i)+0.00001
    else:
        print(f"0 {comp}(s) de R$ {i:.2f}")