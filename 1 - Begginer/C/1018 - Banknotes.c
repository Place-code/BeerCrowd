#include <stdio.h>

int main() {
    
    int N, N_i, N_100, N_50, N_20, N_10, N_5, N_2, N_1;
    
    scanf("%d", &N);
    N_i = N;

    int n[7] = {0, 0, 0, 0, 0, 0, 0};

    while (N >= 100)
    {
        n[0]+=1;
        N-=100;
    }

    while (N >= 50)
    {
        n[1]+=1;
        N-=50;
    }

    while (N >= 20)
    {
        n[2]+=1;
        N-=20;
    }

    while (N >= 10)
    {
        n[3]+=1;
        N-=10;
    }

    while (N >= 5)
    {
        n[4]+=1;
        N-=5;
    }
    
    while (N >= 2)
    {
        n[5]+=1;
        N-=2;
    }
    
    while (N >= 1)
    {
        n[6]+=1;
        N-=1;
    }


    printf("%d\n%d nota(s) de R$ 100,00\n%d nota(s) de R$ 50,00\n%d nota(s) de R$ 20,00\n%d nota(s) de R$ 10,00\n%d nota(s) de R$ 5,00\n%d nota(s) de R$ 2,00\n%d nota(s) de R$ 1,00\n", N_i, n[0], n[1], n[2], n[3], n[4], n[5], n[6]);
    
    return 0;
}