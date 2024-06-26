for i in range(int(input())):
    x=int(input())
    prin= f"{((2**x)/1000/12):.5f}"
    for j in prin:
        if j=='.': break
        print(j, end='')
    print(' kg')