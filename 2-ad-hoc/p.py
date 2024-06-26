from decimal import Decimal
r = [0,1]
c = 1
for i  in r:
    def cal():
        #Armazenadores
        ar_b = [0]#Básico
        ar_a = [0]#Avançado
        ar_pa = [0]#Parentestes
        #Arquivamento
        m_guardado = []
        o_guardado = []
        mar1 = 0#marcador
        #Ativador
        ativar = 0
        #Contador
        contador = []
        #Estados
        est = 0
        est_sub = 0
        est_p = 0
        #Estágios
        e = 0#normal
        ex = 0
        e_m = 0
        e_sub = 0
        #Erro
        error = [0,1]
        #Exlcuição
        e_e = 0
        #Finalização
        f = 0
        #Inputs
        x = [1,2]
        #Listas
        n = []#Lista numeral
        os = []#Lista de operações
        g = []#Lista Geral
        gg = []
        #Localização
        local = 0
        #Operaçõs disponiveís
        o_dis = ["+", "-", "*", "/", "^", "r", "(", ")", "ex", "sub", "p", "="]
        #Para!
        para_e = 0
        para_m1 = 0
        para_m2 = 0
        #Totais
        t = 1#Ponte
        t_t = 0#Total toal
        t_m = 1#Total especial
        #Situações
        sit = [0,0,0]
        sit2 = 0
        #Variação
        va = 0
        va_sit = 0
        #Funções:
        def erro(l):
            el = 0
            for i in o_dis:
                if(el == len(o_dis)):
                    print("Inválido, tente novamente")
                    if(sit[0] == 2):
                        return 1,2,0
                    else:
                        g.pop()
                        return [1,0]
                elif(g[l] == i):
                    for i in o_dis[8:]:
                        if(o_dis[el] != i):
                            sit2_interno = 0
                        else:
                            sit2_interno = 1
                            break
                    #DIferente de p
                    if(sit2_interno == 0):
                        if(sit[0] == 2):
                            return 0,2,0
                        else:
                            return 0,0,0
                    #Igual a p ou outros
                    else:
                        if(g[len(g)-1] == "p" or g[len(g)-1] == "P"):
                            g.pop()
                            return 1,3,1
                        elif(g[len(g)-1] == "sub"):
                            g.pop()
                            return 1,3,2
                        elif(g[len(g)-1] == "ex"):
                            g.pop()
                            return 1,3,3
                        elif(g[len(g)-1] == "="):
                            g.pop()
                            return 1,3,4
                el += 1
        for i in x:
            #Número
            if(e % 2 == 0):
                g.append(str(input("N: ")))
            #Operação
            else:
                if(e>0):
                    g.append(str(input("O: ")))
            #Interprete de números
            if(e % 2 == 0):
                for i in error:
                    try:
                        g[e] = float(g[e])
                    except:
                        print("Por favor, não confunda letras com números")
                        error.append(1)
                        try:
                            g[e] = (float(input("N: ")))
                        except:
                            error.append(1)
                    if type(g[e]) is float:
                        n.append(g[e])
                        break
            #Interprete de operações
            else:
                for i in error:
                    #Sem erro
                    if(sit[0] == 0):
                        sit = erro(len(g)-1)
                    elif(sit[0] == 2):
                        if(type (g[local_g]) != float):
                            sit = erro(local_g)
                    if(sit[0] == 0):
                        if(sit[1] == 2):
                            os[local_os] = g[local_g]
                            sit = [1,0,0]
                        else:
                            os.append(g[len(g)-1])
                            break
                    #Erro
                    else:
                        #Inputs
                        if(sit[1] == 0):
                            g.append(str(input("O: ")))
                            sit = [0,0,0]
                        elif(sit[1] == 2):
                            g[local_g] = str(input("O-sub: "))
                            sit = [2,0,0]
                        error.append(1)
                    #Printador
                    if(sit[2] == 1):
                        for i in g:
                            print(i, end=" ")
                        print("\n")
                        sit = [1,0]
                    #Substituidor
                    elif(sit[2] == 2):
                        for i in error:
                            sub = str(input("Sub: "))
                            try:
                                sub = float(sub)
                            except:
                                sub = str(sub)
                            try:
                                g.reverse()
                                local_g = g.index(sub)
                                g.reverse()
                                local_g = (len(g)-1)-local_g
                                if type (sub) is float:
                                    n.reverse()
                                    local_m = n.index(sub)
                                    n.reverse()
                                    local_m = (len(n)-1)-local_m
                                else:
                                    os.reverse()
                                    local_os = os.index(sub)
                                    os.reverse()
                                    local_os = (len(os)-1)-local_os
                                if type (sub) is float:
                                    for i in error:
                                        try:
                                            n_sub = float(input("N-sub: "))
                                        except:
                                            print("Tente novamente")
                                            error.append(1)
                                        else:
                                            break
                                    g[local_g] = n_sub
                                    n[local_m] = n_sub
                                    sit = [1,0]
                                    break
                                else:
                                    # g[local_g] = str(input("O-sub: "))
                                    sit = [1,2]
                                    break
                            except:
                                if type (sub) is float:
                                    print("Não foi possível encontrar o número desejado")
                                    error.append(1)
                                else:
                                    print("Não foi possível encontrar a operação desejada")
                                    error.append(1)
                                n_sub = 1
                    #Excluidor
                    elif(sit[2] == 3):
                        for i in error:
                            try:
                                excluidor = int(input("Ex: "))
                                break
                            except:
                                print("Tente novamente")
                                error.append(1)
                        n.clear()
                        os.clear()
                        while e_e<excluidor:
                            g.pop()
                            e_e += 1
                            if(len(g)-1<0):
                                g.clear()
                                break
                        #Printador
                        for i in g:
                            print(i, end=" ")
                        print("\n")
                        e = len(g)-1
                        if(e == -1):
                            ativar = 0
                            sit = [0,0]
                            break
                        e_e = 0
                        for i in g:
                            if type (i) is float:
                                n.append(i)
                                sit = [1,0,0]
                            else:
                                os.append(i)
                        if type (g[e]) is float:
                            sit = [0,0,0]
                            break
                        else:
                            sit = [0,0,0]
                            break
                    elif(sit[2] == 4):
                        f = 1
                        break
            if(f == 1):
                print("Total:")
                break
            e += 1
            x.append(e+3)
        e = 0
        #Cálculo
        for i in n:
            #Variaveís
            #Parador de operação
            if(e>len(os)-1):
                para_e = 1
            #Números
            n_atual = n[e]
            if(e>0):
                n_ant = n[e-1]
            if(e+1<=len(n)-1):
                n_fut = n[e+1]
            #Operadores
            if(e>len(os)-1):
                e = len(os)
            #Atual
            if(para_e == 0):
                o_atual = os[e]
            else:
                o_atual = os[e-1]
            #Antigo
            if(e == 0):
                o_ant = os[e]
            else:
                if(para_e == 0):
                    o_ant = os[e-1]
                else:
                    o_ant = os[e-1]
            #Futuro
            if(e+1<=len(os)-1):
                o_fut = os[e+1]
            else:
                if(para_e == 0):
                    o_fut = os[e]
                else:
                    o_fut = os[e-1]
            #Estados
            #1-Ad-Sub
            if(o_atual == "+" or o_atual == "-") and (o_ant != "*" and o_ant != "/"):
                t = n_atual
                est = 1
                para_m2 = 0
            #Avaçados
            elif(o_atual == "*") or (o_atual == "/"):
                if(o_fut == "("):
                    est = 3
                else:
                    est = 2
                if(para_m2 != 1):
                    mar1 = e
                    para_m2 = 1
                t = n_atual
            else:
                est = 3
            #Operações
            #Mais
            if(o_atual == "+" and est == 1):
                t = n_atual
            #Menos
            elif(o_atual == "-"):
                n[e+1] = n[e+1]*(-1)
                if(e+1>len(os)-1):
                    os[e] = "+"
            #Mudadores
            #Básico
            if(est == 1):
                ar_b.append(t)
                t = 0
            #Avançado
            elif(est == 2):
                if(e == 0) and (o_atual == "+" or o_atual == "-"):
                    ar_b.append(t)
                else:
                    m_guardado.append(t)
                    o_guardado.append(o_atual)
                    if(e<=len(os)-1):
                        if(o_fut != "*" and o_fut != "/"):
                            m_guardado.append(n_fut)
                            for i in m_guardado:
                                #0
                                if(e_m == 0):
                                    t_m = m_guardado[e_m]
                                #!
                                if(e_m>len(o_guardado)-1):
                                    va = 1
                                if(o_guardado[e_m-va] == "*"):
                                    if(e_m+1<=len(m_guardado)-1):
                                        t_m = t_m*m_guardado[e_m+1]
                                else:
                                    if(e_m+1<=len(m_guardado)-1):
                                        t_m =t_m/m_guardado[e_m+1]
                                e_m += 1
                            e_m = 0
                            ar_a.append(t_m)
                            m_guardado.clear()
                            o_guardado.clear()
                            t_m = 1
                    else:
                        for i in m_guardado:
                            #0
                            if(e_m == 0):
                                t_m = m_guardado[e_m]
                            #!
                            if(e_m>len(o_guardado)-1):
                                    va = 1
                            if(o_guardado[e_m-va] == "*"):
                                if(e_m+1<=len(m_guardado)-1):
                                    t_m = t_m*m_guardado[e_m+1]
                            else:
                                if(e_m+1<=len(m_guardado)-1):
                                    t_m =t_m/m_guardado[e_m+1]
                            e_m += 1
                        e_m = 0
                        ar_a.append(t_m)
                        m_guardado.clear()
                        o_guardado.clear()
                        t_m = 1
            e += 1
            if(e>len(n)-1):
                break
        #Básico
        for i in ar_b:
            gg.append(ar_b[ex])
            ex += 1
        ex = 0
        #Avançado
        for i in ar_a:
            gg.append(ar_a[ex])
            ex += 1
        for i in gg:
            t_t = t_t+i
        if(t_t-int(t_t) != 0):
            t_t_d = Decimal(t_t)
            print(t_t_d)
        else:
            print(int(t_t))
    try:
        cal()
    except ValueError:  
        print("Por favor, coloque números, e não uma língua alienídena aos computadores!")
    except ZeroDivisionError:
        print("Você não achou que isso seria possível, não é?")
    # except:
    #     print("O que você fez!!??")
    c += 1
    r.append(c)