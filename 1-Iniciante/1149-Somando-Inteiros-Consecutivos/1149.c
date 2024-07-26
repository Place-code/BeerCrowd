#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char txt[100];
    int num[100], a, i, n = 0, cont = 0;
    scanf ("%[^\n]",txt);
    char *pt = strtok(txt, " ");
    i = -1;
    while (pt != NULL) {
        i++;
        num[i] = atoi(pt);
        pt = strtok(NULL, " ");
    }
    a = num[0];
    i = 0;
    while (n == 0) {
        i ++;
        if (num[i] > 0) {
            n = num[i];
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        cont += a + i;
    }
    printf ("%d\n", cont);

    return 0;
}