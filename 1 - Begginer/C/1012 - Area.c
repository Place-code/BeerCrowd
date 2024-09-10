#include <stdio.h>
#include <math.h>
 
int main() {
    
    double pi = 3.14159;
    float A, B, C;
    
    scanf("%f %f %f", &A, &B, &C);
    
    float t_3, c, t_4, s, r;
    
    t_3 = A * C / 2;
    c = pi * pow(C, 2);
    t_4 = (A + B) * C / 2;
    s = pow(B, 2);
    r = A * B;
    
    printf("TRIANGULO: %.3f\nCIRCULO: %.3f\nTRAPEZIO: %.3f\nQUADRADO: %.3f\nRETANGULO: %.3f\n", t_3, c, t_4, s, r);
    
    return 0;
}