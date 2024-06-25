for i in range(int(input())):
    x = int(input())
    if x == 0:
        print('NULL')
    else:
        if x%2==0: print('EVEN',end=' ')
        else: print('ODD', end=' ')
        if x<0: print('NEGATIVE')
        else: print('POSITIVE')