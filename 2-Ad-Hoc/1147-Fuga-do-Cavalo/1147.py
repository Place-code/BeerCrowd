cases = 0
while (1):
    inp = input()
    if inp[0] == '0':
        break
    pawns = []
    mov = []
    qnt = 0
    cases += 1
    knight = [int(inp[0]), ord(inp[1])-96]
    for i in range (8):
        inp = input()
        pawns.append((int(inp[0]), ord(inp[1])-96))
    mov.append((knight[0]-2, knight[1]-1))
    mov.append((knight[0]-1, knight[1]-2))
    mov.append((knight[0]+1, knight[1]-2))
    mov.append((knight[0]+2, knight[1]-1))
    mov.append((knight[0]+2, knight[1]+1))
    mov.append((knight[0]+1, knight[1]+2))
    mov.append((knight[0]-2, knight[1]+1))
    mov.append((knight[0]-1, knight[1]+2))
    for pmov in mov:
        if pmov[0] > 0 and pmov[0] < 9 and pmov[1] > 0 and pmov[1] < 9:
            if (pmov[0]+1, pmov[1]+1) not in pawns and (pmov[0]+1, pmov[1]-1) not in pawns:
                qnt += 1
    print ("Caso de Teste #{}: {} movimento(s)." .format(cases, qnt))