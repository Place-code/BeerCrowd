x=float(input())
if x<0 or x>100:
    print("Fora de intervalo")
else:
    if x>=0 and x<=25:
        prin='[0,25]'
    elif x<=50:
        prin='(25,50]'
    elif x<=75:
        prin='(50,75]'
    else:
        prin='(75,100]'
    print('Intervalo',prin)