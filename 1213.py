import sys
sys.set_int_max_str_digits(10000)
while True:
    try:x=int(input())
    except EOFError or ValueError: break
    if x%2!=0 and x%5!=0 and x<10001:
        um='1'*(len(list(str(x))))
        while int(um)%x!=0:
            um+='1'
        print(len(um))