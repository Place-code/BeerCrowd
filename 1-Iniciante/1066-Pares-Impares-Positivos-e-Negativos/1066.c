#include <stdio.h>

int main() {
    int nums[4] = {0, 0, 0, 0}, n;
    for (int i = 0; i <= 4; i++) {
        scanf("%d", &n);
        if (n % 2 == 0) {
            nums[0] += 1;
        }
        else {
            nums[1] += 1;
        }
        if (n > 0) {
            nums[2] += 1;
        }
        else if (n < 0) {
            nums[3] += 1;
        }
    }
    printf ("%d valor(es) par(es)\n", nums[0]);
    printf ("%d valor(es) impar(es)\n", nums[1]);
    printf ("%d valor(es) positivo(s)\n", nums[2]);
    printf ("%d valor(es) negativos(s)\n", nums[3]);

    return 0;
}