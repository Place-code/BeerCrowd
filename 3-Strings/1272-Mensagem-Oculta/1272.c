#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void check (char text[]) {
    bool check = true;
    for (int i = 0; i < 50; ++i) {
        if (text[i] == '\0') {
            break;
        }
        if (text[i] != ' ' && check) {
            printf ("%c", text[i]);
            check = false;
        }
        if (text[i] == ' ') {
            check = true;
        }
    }
    printf ("\n");
}

int main() {
    
    char text[52];
    int n;
    scanf ("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) {
        fgets (text, 52, stdin);
        text[strcspn(text, "\n")] = '\0';
        check(text);
    }
    
    return 0;
}