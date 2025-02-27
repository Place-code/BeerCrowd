#include <stdio.h>
#include <stdbool.h>

int main() {
    int points, quota;
    bool onsequence = false;
    scanf ("%d %d", &points, &quota);
    int dots[points], cnt[points], index = 0, greatest = 0;
    for (int i = 0; i < points; ++i) {
        scanf ("%d", &dots[i]);
        cnt[i] = 0;
    }
    for (int i = 0; i < points-1; ++i) {
        if (dots[i+1] - dots[i] <= quota) {
            onsequence = true;
        }
        else {
            onsequence = false;
            ++index;
        }
        if (onsequence) {
            ++cnt[index];
        }
    }
    for (int i = 0; i < points; ++i) {
        if (cnt[i] > greatest) greatest = cnt[i];
    }
    printf ("%d\n", greatest+1);

    return 0;
}