#include <stdio.h>

int main() {

    char name[50];
    int dates[] = {0, 0, 0, 0, 0, 0};
    scanf ("%[^\n] %d/%d/%d %d/%d/%d", &name, &dates[0], &dates[1], &dates[2], &dates[3], &dates[4], &dates[5]);
    if (dates[0] == dates[3] && dates[1] == dates[4]) {
        printf ("Feliz aniversario!\n");
    }
    if (dates[1] == dates[4] && dates[0] < dates[3] || dates[1] < dates[4]) {
        printf ("Voce tem %d anos %s\n", dates[2] - dates[5] - 1, name);
    }
    else {
        printf ("Voce tem %d anos %s\n", dates[2] - dates[5], name);
    }
    return 0;
}