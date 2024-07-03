x=input().split()
dici={}
for i in range(0,int(x[0]),1):
    inp=input().split()
    dici[inp[0]]=int(inp[1])
nada=input()
runas=input().split()
result=0
for i in runas:
    result+=dici[i]
print(result)
print('You shall pass!') if result>=int(x[1]) else print('My precioooous')