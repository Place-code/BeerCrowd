#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char dados[3002];
    int vals[3];
    fgets (dados, 3002, stdin);
    char *pt = strtok(dados, " ");
    for (int i = 0; i <= 2; ++i) {
        vals[i] = atoi(pt);
        pt = strtok(NULL, " ");
    }
    if (pow(vals[0], 2) == pow(vals[1], 2) + pow(vals[2], 2)) {
        printf ("AREA = %.0f\n", ((vals[2] * vals[1]) / 2) + ((3 * pow(( (float) vals[2] / 2), 2))) / 2);
    }
    else {
        printf ("Nao eh retangulo!\n");
    }
    return 0;
}