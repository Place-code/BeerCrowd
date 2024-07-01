x=int(input())
anos=x//365
restoa=x%365
meses=restoa//30
restom=restoa%30
print(f"{anos} ano(s)")
print(f"{meses} mes(es)")
print(f"{restom} dia(s)")

