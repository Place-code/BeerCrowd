#include <stdio.h>
#include <stdbool.h>

int main() {
    int ncities, nfrontiers, qnt = 0, city1, city2;
    scanf ("%d %d", &ncities, &nfrontiers);
    bool cities[ncities];
    for (int i = 0; i < ncities; ++i) {
        cities[i] = false;
    }
    for (int i = 0; i < nfrontiers; ++i) {
        scanf ("%d %d", &city1, &city2);
        if (!cities[city1-1] && !cities[city2-1]) {
            ++qnt;
        }
        cities[city1-1] = true;
        cities[city2-1] = true;
    }
    for (int i = 0; i < ncities; ++i) {
        if (!cities[i]) ++qnt;
    }
    printf ("%d\n", qnt);
    return 0;
}