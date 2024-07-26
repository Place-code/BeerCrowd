#include <stdio.h>

int main() {

    int a, b;
    scanf ("%d %d", &a, &b);
    if (a % b < 0 && b > 0) {
        printf ("%d %d\n", a / b - 1, a % b + b);
    }
    else if (a % b < 0 && b < 0) {
        printf ("%d %d\n", a / b + 1, a % b - b);
    }
    else {
        printf ("%d %d\n", a / b, a % b);
    }
    return 0;
}