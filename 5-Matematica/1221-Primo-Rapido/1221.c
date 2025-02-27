#include <stdio.h>
#include <math.h>

int main() {

    int i = 1, n, cont;
    long long int x;
    scanf ("%d", &n);
    for (i; i <= n; i++) {
        scanf ("%lld", &x);
        if (x == 2) {
            printf ("Prime\n");
        }
        else {
            for (cont = 2; cont <= ((int) pow(x, 0.5) + 1); cont ++) {
                if (x % cont == 0) {
                    printf ("Not Prime\n");
                    break;
                }
                else if (cont == ((int) pow(x, 0.5) + 1)) {
                    printf ("Prime\n");
                }
            }
        }
    }

    return 0;
}