x=float(input())

notas=(100.0, 50.0, 20.0, 10.0, 5.0, 2.0, 1.0)
print(int(x))
for i in notas:
    if x >= i:
        z=str(i).replace(".", ",")

        print(f"{int(x//i)} nota(s) de R$ {z}0")
        x=x-i*(x//i)
    else:
        z=str(i).replace(".", ",")
        print(f"0 nota(s) de R$ {z}0")