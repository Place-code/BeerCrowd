#include <stdio.h>
#include <math.h>
 
int main() {
    
    double A, R, n = 3.14159;
    
    scanf("%lf", &R);
    
    R = pow(R, 2);
    A = n * R;
    
    printf("A=%.4lf\n", A);
 
    return 0;
}