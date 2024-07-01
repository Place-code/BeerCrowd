for i in range(0,4008):

    entradas=str(input())
    entradas=entradas.split(" ")
    e1=int(entradas[0])
    e2=int(entradas[1])
    e3=int(entradas[2])
    entradas=[e1,e2,e3]
    entradas.sort()
    
    p=(entradas[0]+entradas[1]+entradas[2])/2
    
    
    r=((((p*(p-entradas[0])*(p-entradas[1])*(p-entradas[2]))**0.5)/p)**2*3.1415926535897)
    
    v=((p*(p-entradas[0])*(p-entradas[1])*(p-entradas[2]))**0.5)-r
        
    s=((entradas[0]*entradas[1]*entradas[2])/(v+r)/4)**2*3.1415926535897-(v+r)
    
    print(f"{round(s, 4):.4f} {round(v,4):.4f} {round(r,4):.4f}")