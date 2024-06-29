l=[]
for i in range(0,int(input())):
   l.append(int(input()))
bgl=l[0]
p=0
for i in l:
    if i ==bgl:
        p+=1
        if bgl==1:
            bgl=2
        else:
            bgl=1
print(p)