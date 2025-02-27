#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    bool alpha[26];
    int cases, counter;
    char text[1002];
    scanf ("%d", &cases);
    getchar();
    for (int i = 0; i < cases; ++i) {
        for (int q = 0; q < 26; ++q) {
            alpha[q] = false;
        }
        fgets (text, 1002, stdin);
        text[strcspn(text, "\n")] = '\0';
        for (int q = 0; q < strlen(text); ++q) {
            if (text[q] != ' ' && text[q] != ',') {
                alpha[text[q]-97] = true;
            }
        }
        counter = 0;
        for (int q = 0; q < 26; ++q) {
            if (alpha[q]) {
                ++counter;
            }
        }
        if (counter == 26) {
            printf ("frase completa\n");
        }
        else if (counter >= 13) {
            printf ("frase quase completa\n");
        }
        else {
            printf ("frase mal elaborada\n");
        }
    }
    return 0;
}