for _ in range (int(input())):
    a = int(input())
    if a == 2:
        print ("Prime")
    else:
        for i in range (2, round(a ** 0.5 + 1)):
            if a % i == 0:
                print ("Not Prime")
                break
            elif i == round(a ** 0.5):
                print ("Prime")