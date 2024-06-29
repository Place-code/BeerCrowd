while True:    
    try:
        solds=input().split()
        print(abs(int(solds[1])-int(solds[0])))
    except:
        break