x=[int(input()),int(input())]
tot=0
for i in range(x[1]+1,x[0],1):
	if i%2: tot+=i
print(tot)