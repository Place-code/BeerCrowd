#include <stdio.h>
 
int main() {
 
    int e_n, w_h;
    float r_h, s;
    
    scanf("%d", &e_n);
    scanf("%d", &w_h);
    scanf("%f", &r_h);
    
    s = w_h * r_h;
    
    printf("NUMBER = %d\nSALARY = U$ %.2f\n", e_n, s);
 
    return 0;
}