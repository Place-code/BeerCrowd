for i in range(0,int(input())):
    num=int(input())
    l="Prime"
    if num !=2:
        for i in range(3, int(num**0.5) + 1, 2):
            if num%i==0:
                l="Not Prime"
    print(l)