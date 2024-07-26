while True:
    try:
        a = input().split()
        if int(a[1]) >= int(a[0]): 
            print (int(a[1]) - int(a[0]))
        else:
            print (int(a[0]) - int(a[1]))
    except EOFError:
        break