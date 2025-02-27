#include <stdio.h>

int numerize (char team[]) {
    if (team[0] == 82) {
        return 0;
    }
    else if (team[0] == 71) {
        return 1;
    }
    else {
        return 2;
    }
}

int main() {
    int pitch[3][2] = {{2, 1}, {0, 1}, {1, 0}};
    int cases, goals;
    char ct1[3], ct2[3];
    int t1, t2;
    scanf ("%d", &cases);
    for (int i = 0; i < cases; ++i) {
        int teams[] = {0, 0, 0};
        scanf ("%d", &goals);
        for (int j = 0; j < goals; ++j) {
            scanf ("%s %s", ct1, ct2);
            t1 = numerize(ct1); t2 = numerize(ct2);
            if (pitch[t1][0] == t2) {
                ++teams[t1];
            }
            else {
                teams[t1] += 2;
            }
        }
        if (teams[0] == teams[1] && teams[1] == teams[2]) {
            printf ("trempate\n");
        }
        else {
            if (teams[0] > teams[1] && teams[1] >= teams[2] || teams[0] > teams[2] && teams[2] >= teams[1]) {
                printf ("red\n");
            }
            else if (teams[1] > teams[0] && teams[0] >= teams[2] || teams[1] > teams[2] && teams[2] >= teams[0]) {
                printf ("green\n");
            }
            else if (teams[2] > teams[0] && teams[0] >= teams[1] || teams[2] > teams[1] && teams[1] >= teams[0]) {
                printf ("blue\n");
            }
            else {
                printf ("empate\n");
            }
        }
    }
    return 0;
}