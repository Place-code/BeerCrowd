#include <stdio.h>
# include <math.h>

int main() {
    
    double a, b, c;
    scanf ("%lf %lf %lf", &a, &b, &c);
    if (a == 0 || b * b - 4 * a * c < 0) {
        printf ("Impossivel calcular\n");
    }
    else {
        printf ("R1 = %.5lf\n", (- b + pow((b * b - 4 * a * c), 0.5)) / (2 * a));
        printf ("R2 = %.5lf\n", (- b - pow((b * b - 4 * a * c), 0.5)) / (2 * a));
    }
    
    return 0;
}