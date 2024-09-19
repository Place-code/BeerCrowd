#include <stdio.h>

int main() {
    int N, H, M, S;

    scanf("%d", &N);

    H=0;
    M=0;
    S=N;

    if (S >= 60)
    {
        M = S / 60;
        S = S % 60;

        if (M >= 60)
        {
            H = M / 60;
            M = M % 60;
        }
    }

    printf("%d:%d:%d\n", H, M, S);    

    return 0;
}