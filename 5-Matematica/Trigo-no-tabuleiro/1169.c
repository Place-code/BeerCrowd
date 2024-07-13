#include <stdio.h>
#include <math.h>

int main() {

    int i, n, x;
    unsigned long long wht;
    scanf ("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf ("%d", &x);
        wht = pow(2, x) / 12000;
        printf ("%llu kg\n", wht);
    }
    return 0;
}