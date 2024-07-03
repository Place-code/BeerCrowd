for i in range(int(input())):
    n=input().split()
    ver = True
    tam=[len(n[0]),len(n[1])]
    if tam[0]<tam[1]:
        ver=False
    if ver:
        for i in range(2):
            n[i]=list(n[i])
            n[i].reverse()
        for i in range(min(tam)):
            ver = False if n[1][i]!=n[0][i] else ver
    print('encaixa') if ver else print('nao encaixa')