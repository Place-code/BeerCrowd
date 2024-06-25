x=input().split()
x[0]=int(x[0])
x[1]=int(x[1])
#
quo=x[0]//x[1]
v=x[0]%x[1]
if v<0 and x[1]>0:
    v+=x[1]
    quo-=1
elif v<0 and x[1]<0:
    v-=x[1]
    quo+=1
print(quo,v)