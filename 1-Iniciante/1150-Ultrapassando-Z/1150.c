#include <stdio.h>

int main() {

    int x, z, cont = 2;
    scanf ("%d %d", &x, &z);
    while (z <= x) {
        scanf ("%d", &z);
    }
    for (int i = x + 1; i + x <= z; i++) {
        if (x + i <= z) {
            x += i;
            cont++;
        }
    }
    printf ("%d\n", cont);

    return 0;
}