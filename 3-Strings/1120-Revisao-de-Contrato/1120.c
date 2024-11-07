#include <stdio.h>
#include <stdbool.h>

void correct (char term[], char text[]) {
    const int len = 101;
    char newtext[len];
    int index = 0;
    for (int i = 0; i < len; ++i) {
        if (text[i] == '\0') {
            newtext[index] = '\0';
            break;
        }
        if (text[i] != term[0]) {
            newtext[index] = text[i];
            ++index;
        }
    }
    if (newtext[0] == '\0') {
        printf ("0\n");
    }
    else if (newtext[0] == '0'){
        bool oncheck = true;
        char corrected[len];
        index = 0;
        for (int i = 0; i < len; ++i) {
            if (newtext[i] == '\0') {
                corrected[index] = '\0';
                break;
            }
            if (newtext[i] != '0') {
                oncheck = false;
                corrected[index] = newtext[i];
                ++index;
            }
            else if (!oncheck) {
                corrected[index] = newtext[i];
                ++index;
            }
        }
        if (corrected[0] == '\0') {
            printf ("0\n");
        }
        else {
            printf ("%s\n", corrected);   
        }
    }
    else {
        printf ("%s\n", newtext);
    }
}
int main() {
    for (;;) {
        char term[2], text[101];
        scanf ("%s %s", term, text);
        getchar();
        if (text[0] == '0' && term[0] == '0') {
            break;
        }
        correct(term, text);   
    }
    return 0;
}