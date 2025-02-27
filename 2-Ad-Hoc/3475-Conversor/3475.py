converser = ["zero", "um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"]
inp = input()
try:
    print (converser[int(inp)])
except:
    print (converser.index(inp))