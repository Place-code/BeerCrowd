x=int(input())
segs=0
min=0
hrs=0
for i in range(1,x+1):
    if i%60==0:
        min+=1
        segs=0
    else:
        segs+=1
    if min%60==0 and min!=0:
        hrs+=1
        min=0
print(f"{hrs}:{min}:{segs}")