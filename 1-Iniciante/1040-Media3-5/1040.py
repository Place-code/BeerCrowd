x=str(input())
x=x.split(" ")
n1=float(x[0])
n2=float(x[1])
n3=float(x[2])
n4=float(x[3])
med=(n1*2+n2*3+n3*4+n4)/10
print(f"Media: {med:.1f}")
if med>=7:
    print("Aluno aprovado.")
elif med>=5:
    print("Aluno em exame.")
    x=float(input())
    print(f"Nota do exame: {x:.1f}")
    med=(med+x)/2
    if med>=5:
        print("Aluno aprovado.")
    else:
        print("Aluno reprovado.")
    print(f"Media final: {med:.1f}")
else:
    print("Aluno reprovado.")