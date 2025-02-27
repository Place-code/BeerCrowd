def getcpf(text):
    cpf = ''
    remainent = ''
    for i in range (11):
        cpf += text[i]
    for i in range(11, len(text)):
        remainent += text[i]
    return [cpf, remainent]
    
def numerize(text):
    numerized = ''
    checkpoint = False
    pindex = 0
    for i in text:
        if i.isdigit() or i == '.':
            numerized += i
            if i == '.':
                checkpoint = True
            if checkpoint:
                pindex += 1
                if pindex == 3:
                    break
    return numerized

input1 = input()
input1 = getcpf(numerize(input1))
input2 = input()
input2 = numerize(input2)
input2 = float(input1[1]) + float(input2)
print ("cpf {}\n{:.2f}" .format(input1[0], input2))