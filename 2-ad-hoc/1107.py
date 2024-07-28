ant_n=0
while True:
    v=input().split()
    vv=[int(_) for _ in v]
    if vv[0]==0 and vv[1]==0:
        break
    ind=input().split()
    ind_i=[int(_) for _ in ind]
    p=vv[0]-ind_i[0]
    for _ in ind_i:
        if ant_n>_:
            p+=(ant_n-_)
        ant_n=_
    print(p)
    vv.clear()
    ind_i.clear() 