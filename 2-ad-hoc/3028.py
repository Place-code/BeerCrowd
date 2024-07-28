n_ant='1'
v=1
for i in range(int(input())):
    x=input() 
    if x!=n_ant:
        n_ant=x
        v+=1
print(v)