for i in range(int(input())):
    x=input()
    print(int(x[0])*int(x[2]))if x[0]==x[2]else print(int(x[2])-int(x[0]))if ord(x[1])<91 else print(int(x[0])+int(x[2]))
