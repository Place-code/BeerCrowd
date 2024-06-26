while(True):
    x=1
    x=int(input())
    if x!=0:
        cor_n=[0,0]
        inp=input().split()
        cor_n[0]=int(inp[0]);cor_n[1]=int(inp[1])
        for i in range(x):
            inp=input().split()
            if cor_n[0]==int(inp[0])or cor_n[1]==int(inp[1]): print('divisa')
            else:
                x=int(inp[0])-cor_n[0]
                y=int(inp[1])-cor_n[1]
                prin=''
                if y>0: prin+='N'
                else:prin+='S'
                if x>0: prin+='E'
                else: prin+='O'
                print(prin)
    else:break