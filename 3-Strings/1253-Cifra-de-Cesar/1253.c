#include <stdio.h>
#include <string.h>

void ceasar(char text[], int justify) {
    int len = strlen(text);
    for (int i = 0; i < len; ++i) {
        if (text[i] == '\0') {
            text[i] = '\0';
            break;
        }
        if (text[i] - justify < 'A') {
            text[i] = text[i] - justify + 26;
        }
        else {
            text[i] = text[i] - justify;
        }
    }
    printf ("%s\n", text);
}

int main() {
    char text[51];
    int justify, n;
    scanf ("%d", &n);
    getchar();
    for (int q = 0; q < n; ++q) {
        fgets (text, 51, stdin);
        text[strcspn(text, "\n")] = '\0';
        scanf ("%d", &justify);
        getchar();
        ceasar(text, justify);
    }
    return 0;
}