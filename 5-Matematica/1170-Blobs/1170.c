#include <stdio.h>

int main() {
    int len;
    float num;
    scanf ("%d", &len);
    for (int i = 0; i < len; ++i) {
        int qt=0;
        scanf ("%f", &num);
        while (num > 1) {
            num -= num/2;
            ++qt;
        }
        printf ("%d dias\n", qt);
    }

    return 0;
}