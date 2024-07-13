#include <stdio.h>

int main() {

    int n, analog;
    scanf ("%d", &n);
    analog = n;
    int qnt[7] = {0, 0, 0, 0, 0, 0, 0};
    if (n >= 100) {
        qnt[0] = n / 100;
        n -= 100 * (n / 100);
    };
    if (n >= 50) {
        qnt[1] = n / 50;
        n -= 50 * (n / 50);
    };
    if (n >= 20) {
        qnt[2] = n / 20;
        n -= 20 * (n / 20);
    };
    if (n >= 10) {
        qnt[3] = n / 10;
        n -= 10 * (n / 10);
    };
    if (n >= 5) {
        qnt[4] = n / 5;
        n -= 5 * (n / 5);
    };
    if (n >= 2) {
        qnt[5] = n / 2;
        n -= 2 * (n / 2);
    };
    if (n >= 1) {
        qnt[6] = n;
    };
    printf ("%d\n", analog);
    printf ("%d nota(s) de R$ 100,00\n", qnt[0]);
    printf ("%d nota(s) de R$ 50,00\n", qnt[1]);
    printf ("%d nota(s) de R$ 20,00\n", qnt[2]);
    printf ("%d nota(s) de R$ 10,00\n", qnt[3]);
    printf ("%d nota(s) de R$ 5,00\n", qnt[4]);
    printf ("%d nota(s) de R$ 2,00\n", qnt[5]);
    printf ("%d nota(s) de R$ 1,00\n", qnt[6]);

    return 0;
}