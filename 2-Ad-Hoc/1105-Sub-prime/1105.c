#include <stdio.h>
#include <stdbool.h>

int main() {
    int nbanks, nfare, d, c, v;
    while (1) {
        scanf ("%d %d", &nbanks, &nfare);
        if (nbanks == 0 && nfare == 0) break;
        int banks[nbanks];
        for (int i = 0; i < nbanks; ++i) scanf ("%d", &banks[i]);
        for (int i = 0; i < nfare; ++i) {
            scanf ("%d %d %d", &d, &c, &v);
            banks[d-1] -= v;
            banks[c-1] += v;
        }
        bool able = true;
        for (int i = 0; i < nbanks; ++i) {
            if (banks[i] < 0) {
                able = false;
                break;
            }
        }
        if (able) {
            printf ("S\n");
        }
        else {
            printf ("N\n");
        }
    }
    return 0;
}