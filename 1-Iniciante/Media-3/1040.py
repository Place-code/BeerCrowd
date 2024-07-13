n = input().split()
media = round((float(n[0]) * 2 + float(n[1]) * 3 + float(n[2]) * 4 + float(n[3])) / 10, 1)
print ("Media:",media)
if media >= 7:
    print ("Aluno aprovado.")
elif media < 5:
    print ("Aluno reprovado.")
elif media >= 5 and media <= 6.9:
    print ("Aluno em exame.")
    e = float(input())
    print("Nota do exame:", e)
    media = (media + e) / 2
    if media > 5:
        print ("Aluno aprovado.")
    else:
        print ("Aluno reprovado.")
    print ("Media final:", media)