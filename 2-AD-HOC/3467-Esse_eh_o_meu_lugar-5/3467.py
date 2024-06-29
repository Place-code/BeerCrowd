while True:
    try:
        x=str(input())
        if x[2]=="L" or x[2]=="l":
            print("Esse eh o meu lugar")
        else:
            print("Oi, Leonard")
    except:
        break