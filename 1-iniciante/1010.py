v = [input().split() for x in range(2)]
print('VALOR A PAGAR: R$',f"{int(v[0][1])*float(v[0][2])+float(v[1][1])*float(v[1][2]):.2f}")