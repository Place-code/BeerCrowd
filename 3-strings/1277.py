def seventyFive(string)->None:
    lengthString,presence=0,0
    for i in string:
        if i=='M':continue
        presence+=1 if i=='P' else 0
        lengthString+=1
    return presence/lengthString>=0.75
for i in range(int(input())):
    input()
    names=input().split()
    prin=[]
    index=0
    for i in input().split():
        if not seventyFive(i): prin.append(names[index])
        index+=1
    if not len(prin):print();continue
    for i in range(len(prin)-1):
        print(prin[i],end=' ')
    print(prin[-1])
