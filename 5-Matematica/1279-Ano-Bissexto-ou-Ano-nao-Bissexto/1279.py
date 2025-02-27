pres = False
store = []
while (1):
    try:
        store.append(list(map(int, input())))
    except EOFError:
        for number in store:
            if pres:
                print ()
            pres = True
            isleap, ishuluculu = False, False
            ppar, pimpar = 0, 0
            
            for index, i in enumerate (number):
                if index % 2 == 0:
                    ppar += i
                else:
                    pimpar += i
            if ((number[-2]*10 + number[-1]) % 4 == 0 and (number[-2] != 0 or number[-1] != 0)) or ((number[-2] == 0 and number[-1] == 0) and ((number[-4]*10 + number[-3]) * 100) % 400 == 0):
                print ("This is leap year.")
                isleap = True
            if (((ppar + pimpar) % 3 == 0) and (number[-1] == 0 or number[-1] == 5)):
                print ("This is huluculu festival year.")
                ishuluculu = True
            if ((ppar - pimpar) % 11 == 0 and isleap):
                print ("This is bulukulu festival year.")
            elif not isleap and not ishuluculu:
                print ("This is an ordinary year.")
        break