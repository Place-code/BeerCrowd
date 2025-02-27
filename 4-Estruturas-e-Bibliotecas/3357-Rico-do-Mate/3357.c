#include <stdio.h>
#include <string.h>

int main() {
    int people, dose = 1, index;
    float bottle, bowl;
    scanf ("%d %f %f", &people, &bottle, &bowl);
    char contestants[people][12];
    for (int i = 0; i < people; ++i) {
        scanf ("%s", contestants[i]);
    }
    while (bottle-bowl*dose > 0) {
        ++dose;
    }
    --dose; index = dose%people;
    for (int i = 0; i < strlen(contestants[index]); ++i) {
        printf ("%c", contestants[index][i]);
    }
    printf (" %.1f\n", bottle-bowl*dose);
    return 0;
}