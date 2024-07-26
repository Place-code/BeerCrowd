#include <stdio.h>

int main() {

    int i, days, money, r, list[30], palp = 10000000;
    scanf ("%d %d", &days, &money);
    for (i = 0; i < days; i++) {
        scanf ("%d", &r);
        money += r;
        list[i] = money;
    }
    for (i = 0; i < days; i++) {
        if (list[i] < palp) {
            palp = list[i];
        }
    }
    printf ("%d\n", palp);

    return 0;
}