#include <stdio.h>
 
int main() {
 
    int T, S;
    float L;
    
    scanf("%d %d", &T, &S);

    L = T * S / 12.0;

    printf("%.3f\n", L);
 
    return 0;
}