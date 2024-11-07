#include <stdio.h>

void mdc(int x, int y) {
    int mod = x % y;
    while (mod != 0) {
        x = y;
        y = mod;
        mod = x % y;
    }
    printf ("%d\n", y);
}
int main() {
    int a, b, n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf ("%d %d", &a, &b);
        mdc(a, b);  
    }
    return 0;
}