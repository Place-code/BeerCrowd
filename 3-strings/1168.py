for i in range(int(input())):
    led=input()
    luz=0
    for i in led:
        if i=="1":luz+=2
        elif i=='2' or i=='3' or i=='5':luz+=5
        elif i=='4':luz+=4
        elif i=='6'or i=='9'or i=='0':luz+=6
        elif i=='7':luz+=3
        else: luz+=7
    print(luz,'leds')