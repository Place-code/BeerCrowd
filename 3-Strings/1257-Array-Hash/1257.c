#include <stdio.h>

int main() {
    int cases, el, sum = 0;
    scanf ("%d", &cases);
    for (int i = 0; i < cases; ++i) {
        scanf ("%d", &el);
        for (int q = 0; q < el; ++q) {
            char text[50];
            scanf ("%s", text);
            for (int z = 0; z <= 50; ++z) {
                if (text[z] == '\0') {
                    break;
                }
                sum += (text[z] - 65) + z + q;
            }
        }
        printf ("%d\n", sum);
        sum = 0;
    }
    return 0;
}