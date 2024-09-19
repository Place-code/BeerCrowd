N = int(input(""))
N_i = N

N_100, N_50, N_20, N_10, N_5, N_2, N_1 = [0] * 7

while (N >= 100):
    N_100+=1
    N-=100

while (N >= 50):
    N_50+=1
    N-=50

while (N >= 20):
    N_20+=1
    N-=20

while (N >= 10):
    N_10+=1
    N-=10

while (N >= 5):
    N_5+=1
    N-=5

while (N >= 2):
    N_2+=1
    N-=2

while (N>= 1):
    N_1+=1
    N-=1

print(f"{N_i}\n{N_100} nota(s) de R$ 100,00\n{N_50} nota(s) de R$ 50,00\n{N_20} nota(s) de R$ 20,00\n{N_10} nota(s) de R$ 10,00\n{N_5} nota(s) de R$ 5,00\n{N_2} nota(s) de R$ 2,00\n{N_1} nota(s) de R$ 1,00")