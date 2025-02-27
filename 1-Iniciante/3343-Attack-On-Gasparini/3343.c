#include <stdio.h>

int main() {
    int n, x, hit, len = 1;
    scanf ("%d %d", &n, &x);
    char Sattacks[n];
    scanf ("%s", Sattacks);
    int damage[3], attacks[n], indexes[] = {0, 0, 0}, walls[n];
    walls[0] = x;
    for (int i = 0; i < n; ++i) {
        if (Sattacks[i] == 'P') {
            attacks[i] = 0;
        }
        else if (Sattacks[i] == 'M') {
            attacks[i] = 1;
        }
        else {
            attacks[i] = 2;
        }
    }
    scanf("%d %d %d", &damage[0], &damage[1], &damage[2]);
    for (int i = 0; i < n; ++i) {
        hit = damage[attacks[i]];
        while (walls[indexes[attacks[i]]] < hit) {
            ++indexes[attacks[i]];
            if (indexes[attacks[i]] == len) {
                walls[len] = x;
                ++len;
            }
        }
        walls[indexes[attacks[i]]] -= hit;
    }
    printf ("%d\n", len);
    return 0;
}