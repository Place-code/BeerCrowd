#include <stdio.h>
#include <stdlib.h>

int main() {

    int a, b, c;
    scanf ("%d %d %d", &a, &b, &c);
    if (((a + b + abs(a - b)) / 2) > c) {
        printf ("%d eh o maior\n", (a + b + abs(a - b)) / 2);
    }
    else {
        printf ("%d eh o maior\n", c);
    }

    return 0;
}