#include <stdio.h>

int main () {
    
    double A, B, m;
    
    scanf("%lf", &A);
    scanf("%lf", &B);
    
    m = (A*3.5 + B*7.5) / 11;
    
    printf("MEDIA = %.5lf\n", m);
    
    return 0;
}