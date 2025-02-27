while (True):
    try:
        val1, val2 = input().split()
        print (int(val1) ^ int(val2))
    except EOFError:
        break