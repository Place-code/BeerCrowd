#include <stdio.h>
#include <string.h>

void decript(char text[]) {
    int len = strlen(text), index = 0;
    char uncripted[102] = {};
    for (int i = len/2 -1; i >= 0; --i) {
        uncripted[index] = text[i];
        ++index;
    }
    for (int i = len - 1; i > len/2 - 1; --i) {
        uncripted[index] = text[i];
        ++index;
    }
    printf ("%s\n", uncripted);
}

int main() {
    char txt[102];
    int len;
    scanf ("%d", &len);
    getchar();
    for (int i = 0; i < len; ++i) {
        fgets(txt, 102, stdin);
        txt[strcspn(txt, "\n")] = '\0';
        decript(txt);
    }
    return 0;
}