x=input().split(" ")
m=(float(x[0])*2+float(x[1])*3+float(x[2])*4+float(x[3]))/10
print('Media:',f"{m:.1f}")
if m>=7: print('Aluno aprovado.')
elif m>=5 and m<7:
    print('Aluno em exame.')
    m1=float(input())
    print('Nota do exame:', m1)
    if (m+m1)/2>5: print('Aluno aprovado.')
    else: print('Aluno reporavo.')
    print('Media final:',f"{(m+m1)/2:.1f}")
else:
    print('Aluno reprovado.')