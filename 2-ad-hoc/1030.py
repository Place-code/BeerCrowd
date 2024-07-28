for i in range(int(input())):
    x=input().split()
    p=0
    for j in range(1,int(x[0])+1,1):
        p=(p+int(x[1]))%j
    print("Case",str(i)+':',p+1)