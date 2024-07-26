#include <stdio.h>
#include <math.h>

int main() {

    int c, n;
    scanf ("%d", &c);
    for (int i = 0; i < c; i++) {
        scanf ("%d", &n);
        printf ("%.3f\n", pow((float) n, 2) * 0.25 * pow((5 * (5 + 2 * pow(5, 0.5))), 0.5));
    }

    return 0;
}