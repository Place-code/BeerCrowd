#include <stdio.h>
#include <stdbool.h>

int main() {

    int h1 = 1, m1 = 1, h2 = 1, m2 = 1;
    while (true) {
        scanf ("%d %d %d %d", &h1, &m1, &h2, &m2);
        if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0) {
            printf ("\n");
            break;
        }
        if (h1 == 0){
        h1 = 24;
        }
        else if (h2 == 0) {
            h2 = 24;
        }
        if (h1 < h2 || h1 == h2 && m1 <= m2 ) {
            printf ("%d\n",(h2 * 60 + m2) - (h1 * 60 + m1));
        }
        else {
            printf ("%d\n", (h2 * 60  + 24 * 60 + m2) - (h1 * 60 + m1));
        }
    }


    return 0;
}