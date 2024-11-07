#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main() {
    int qnt;
    while (scanf ("%d", &qnt) != EOF) {
        int salt, moda[20], soma = 0;
        bool comp = true;
        for (int i = 0; i <= qnt - 1; ++i) {
            scanf ("%d", &moda[i]);
        }
        scanf ("%d", &salt);
        qnt -= 1;
        for (qnt; qnt >= 0; qnt -= salt) {
            soma += moda[qnt];
        }
        if (soma != 1) {
            for (int i = 2; i <= (int) pow(soma, 0.5); ++i) {
                if (soma % i == 0) {
                    comp = false;
                    break;
                }
            }   
        }
        else {
            comp = false;
        }
        if (comp) {
            printf ("You’re a coastal aircraft, Robbie, a large silver aircraft.\n");
        }
        else {
            printf ("Bad boy! I’ll hit you.\n");
        }
    }
    return 0;
}