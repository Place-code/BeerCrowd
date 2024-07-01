per=str(input())
per=per.split(" ")
per=[int(per[0]), int(per[1]), int(per[2]),int(per[3])]
hrs=0
if per[0]<=per[2]:
    hrs= per[2]-per[0]
    
    minu=per[3]-per[1]
    if per[1]>per[3]:
        hrs-=1
        minu=60-(per[1]-per[3])
        
    if per[0]==per[1]and per[0]==per[2]and per[0]== per[3]:
        hrs=24
        minu=0
else:
    hrs=(24-per[0])+per[2]
    minu=per[3]-per[1]
    if per[1]>per[3]:
        hrs-=1
        minu=60-(per[1]-per[3])
if hrs == -1:
    hrs=23
print(f"O JOGO DUROU {hrs} HORA(S) E {minu} MINUTO(S)")