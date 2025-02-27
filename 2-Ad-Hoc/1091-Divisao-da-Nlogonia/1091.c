#include <stdio.h>

int main() {
    int cases, dx, dy, hx, hy;
    while (1) {
        scanf("%d", &cases);
        if (cases == 0) break;
        scanf ("%d %d", &dx, &dy);
        for (int i = 0; i < cases; ++i) {
            scanf ("%d %d", &hx, &hy);
            if (hx == dx || hy == dy) {
                printf ("divisa\n");
            }
            else {
                if (hx > dx) {
                    if (hy > dy) {
                        printf ("NE\n");
                    }
                    else {
                        printf ("SE\n");
                    }
                }
                else {
                    if (hy > dy) {
                        printf ("NO\n");
                    }
                    else {
                        printf ("SO\n");
                    }
                }   
            }
        }
    }

    return 0;
}