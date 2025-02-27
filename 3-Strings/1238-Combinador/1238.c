#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void combine(char word1[], char word2[]) {
    char combined[104] = {};
    int adjust = 0;
    bool check1 = true, check2 = true, correct = true;
    for (int i = 0; i < 52; ++i) {
        if (!check1 && !check2) {
            break;
        }
        if (check1) {
            if (word1[i] != '\0') {
                combined[i+adjust] = word1[i];
                if (check2) {
                    ++adjust;
                }
            }
            else {
                check1 = false;
                if (check2) {
                    combined[i+adjust] = word2[i];
                    correct = false;
                }
            }
        }
        if (check2 && correct) {
            if (word2[i] != '\0') {
                combined[i+adjust] = word2[i];
            }
            else {
                --adjust;
                check2 = false;
            }   
        }
        correct = true;
    }
    printf ("%s\n", combined);
}

int main() {
    int len;
    char text1[52], text2[52], combined[104];
    scanf ("%d", &len);
    for (int i = 0; i < len; ++i) {
        getchar();
        scanf ("%s %s", text1, text2);
        text2[strcspn(text2, "\n")] = '\0';
        combine(text1, text2);
    }
    return 0;
}