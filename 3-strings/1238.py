for i in range(int(input())):
    [str1,str2]=input().split()
    for i in range(max(len(str1),len(str2))):
        if i<len(str1):
            print(str1[i],end='')
        if i<len(str2):
            print(str2[i],end='')
    print()
