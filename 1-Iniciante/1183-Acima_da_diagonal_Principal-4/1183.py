x=[[],[],[],[],[],[],[],[],[],[],[],[]]
nx=[12*1,12*2,12*3,12*4,12*5,12*6,12*7,12*8,12*9, 12*10, 12*11, 12*12]
o=str(input())
c=0
for i in range (1,12*12+1):
    x[c].append(float(input()))
    if i in nx:
        c+=1
bgl=[]
lo=1
for i in x:
    bgl.append(sum(i[lo:]))
    lo+=1
if o =="S":
    print(f"{sum(bgl):.1f}")
else:
    print(f"{sum(bgl)/66:.1f}")