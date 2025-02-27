#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char text[52];
    bool icheck = false, bcheck = false;
    while (fgets(text, 52, stdin) != NULL) {
        for (int i = 0; i < strlen(text); ++i) {
            if (text[i] == '_') {
                if (icheck) {
                    printf ("</i>");
                    icheck = false;
                }
                else {
                    printf ("<i>");
                    icheck = true;
                }
            }
            else if (text[i] == '*') {
                if (bcheck) {
                    printf ("</b>");
                    bcheck = false;
                }
                else {
                    printf ("<b>");
                    bcheck = true;
                }
            }
            else {
                putchar(text[i]);
            }
        }
    }
    return 0;
}