while True:
    try:
        x=input()
        v_a=0
        passou=True
        ordi=True
        e=1
        par=0
        inp=0
        for i in x:
            v_a+=int(i)
            if e%2!=0: inp+=int(i)
            else: par+=int(i)
            e+=1
        if int(x[len(x)-2]+x[len(x)-1])%4==0 and int(x[len(x)-4]+x[len(x)-3]+x[len(x)-2]+x[len(x)-1])%100!=0:
            print('This is leap year.')
            if v_a%3==0:
                if x[len(x)-1]=='5'or x[len(x)-1]=='0':
                    print('This is huluculu festival year.')
                    passou=False
            if par-inp==0 or (par-inp)%11==0:
                print('This is bulukulu festival year.')
            ordi=False
        elif int(x[len(x)-4]+x[len(x)-3]+x[len(x)-2]+x[len(x)-1])%400==0:
            print('This is leap year.')
            if v_a%3==0:
                if x[len(x)-1]=='5'or x[len(x)-1]=='0':
                    print('This is huluculu festival year.')
                    passou=False
            if par-inp==0 or (par-inp)%11==0:
                print('This is bulukulu festival year.')
            ordi=False
        if passou and v_a%3==0:
            if x[len(x)-1]=='5'or x[len(x)-1]=='0':
                print('This is huluculu festival year.')
                ordi=False
        if ordi:
            print('This is an ordinary year.')
        x=''
        print('\r')
    except: break