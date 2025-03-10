def spore(issuer,receiver)->int:
    if issuer==ord('R') and receiver==ord('G'):
        return 2
    elif issuer==ord('R'):
        return 1

    if issuer==ord('G')and receiver==ord('B'):
        return 2
    elif issuer==ord('G'):
       return 1

    if issuer==ord('B') and receiver==ord('R'):
       return 2
    else:
       return 1

for i in range(int(input())):
    score=[0,0,0]
    for j in range(int(input())):
        [str_1_chr,str_2_chr]=input().split()

        str_1_chr=ord(str_1_chr) 
        str_2_chr=ord(str_2_chr)

        if str_1_chr==ord('R'):
            score[0]+=spore(str_1_chr,str_2_chr);
        if str_1_chr==ord('G'):
            score[1]+=spore(str_1_chr,str_2_chr);
        if str_1_chr==ord('B'):
            score[2]+=spore(str_1_chr,str_2_chr);

    if score[0]>score[1] and score[0]>score[2]:
        print("red")
    elif score[1]>score[0] and score[1]>score[2]:
        print("green")
    elif score[2]>score[0] and score[2]>score[1]:
        print("blue")
    elif score[0]==score[1] and score[0]==score[2]:
        print("trempate")
    else:
        print("empate")

