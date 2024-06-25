for i in range(int(input())):
    x=input().split()
    lis_x=[float(j) for j in x]
    lis_x[0]*=2;lis_x[1]*=3;lis_x[2]*=5
    m=0
    for i in lis_x:
        m+=i
    m/=10
    print(f"{m:.1f}")