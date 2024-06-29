x=str(input())
c=0
if x.count("O")!=1:
    print("?")
else:
    for i in range(0,2):
        if x[i]=="X" and x[i+1]=="X":
            print("Alice")
            c=1
    if x=="XOX":
        print("*")