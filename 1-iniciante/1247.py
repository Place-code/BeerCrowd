import math
while True:
    try: v1,v2,v3=map(int,input().split())
    except: break
    h=pow((pow(v1,2)+144),0.5)
    print('S') if 12/v2>=h/v3 else print('N')