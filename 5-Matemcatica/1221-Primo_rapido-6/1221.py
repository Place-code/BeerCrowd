for i in range(int(input())):
    x = int(input()); v = False
    for j in range(2,int(round(x**0.5))):
        if x % j ==0: v = True; break
    if v == False: print('Prime')
    else: print('Not Prime')