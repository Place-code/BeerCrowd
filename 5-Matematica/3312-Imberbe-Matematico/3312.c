#include <stdio.h>
#include <math.h>

int main() {

    int n, size = 0;
    unsigned long long x, fat[50], nums[50];
    scanf ("%d", &n);
    for (int i = 0; i <= n - 1; i++) {
        scanf ("%llu", &x);
        int q = 2;
        for (q; q <= ((int) pow(x, 0.5) + 1); q++) {
            if (x % q == 0) {
                break;
            }
        }
        if (q == ((int) pow(x, 0.5) + 1) && x % q != 0 || x == 2) {
            nums[size] = x;
            for (q = x - 1; q >= 2; q--) {
                x *= q;
            }
            fat[size] = x;
            size++;
        }
    }
    for (int i = 0; i <= 2; i++) {
        printf ("%llu! = %llu\n", nums[i], fat[i]);
    }
    return 0;
}