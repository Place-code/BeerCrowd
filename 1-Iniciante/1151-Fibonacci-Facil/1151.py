a = int(input())
num = 0
ant = 0 
antsuc = 1
print (0, "" ,end='')
for _ in range (a - 1):
    num = ant + antsuc
    if _ != a - 2:
        print (num,"",end='')
    else:
        print (num)
    antsuc = ant
    ant = num