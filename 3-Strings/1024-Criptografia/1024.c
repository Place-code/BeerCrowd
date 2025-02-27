#include <stdio.h>
#include <string.h>

void cript(char text[]) {
    for (int i = 0; i < strlen(text); ++i) {
        text[i] = (text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z') ? text[i] + 3 : text[i];
    }
    char newtext[1002] = {};
    int index = 0;
    for (int i = strlen(text); i >= 0; --i) {
        if (text[i] != '\0') {
            newtext[index] = text[i];
            ++index;
        }
    }
    for (int i = strlen(newtext) / 2; i < strlen(newtext); ++i) {
        --newtext[i];
    }
    printf ("%s\n", newtext);
}

int main() {
    
    char text[1002];
    int n;
    scanf ("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) {
        fgets(text, 1002, stdin);
        text[strcspn(text, "\n")] = '\0';
        cript(text);
    }
    
    return 0;
}