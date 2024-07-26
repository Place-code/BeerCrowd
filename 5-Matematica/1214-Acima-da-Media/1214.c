#include <stdio.h>

int main() {

    int n, alu;
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) {
        int notas[1001] = {};
        scanf ("%d", &alu);
        for (int q = 1; q <= alu; q++) {
            scanf ("%d", &notas[q]);
            notas[0] += notas[q];
        }
        int cont = 0;
        for (int q = 1; q <= alu; q++) {
            if (notas[q] > (float) (notas[0] / alu)) {
                cont ++;
            }
        }
        printf ("%.3f%\n", ((float)cont / alu) * 100);
    }

    return 0;
}