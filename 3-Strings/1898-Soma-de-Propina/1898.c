#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void checkmoney(char money[], char text[], int index, int len) {
    int index2 = 0, pindex = 0;
    bool gotpoint = false;
    for (int i = index; i < len; ++i) {
        if (isdigit(text[i]) || text[i] == '.') {
            money[index2] = text[i];
            if (text[i] == '.') {
                gotpoint = true;
            }
            if (gotpoint) {
                ++pindex;
                if (pindex == 3) {
                    break;
                }
            }
            ++index2;
        }
    }
}

void check(char text1[], char text2[]) {
    char cpf[13] = {};
    int index1 = 0, index2 = 0;
    for (int i = 0; i < strlen(text1); ++i) {
        if (isdigit(text1[i])) {
            cpf[index1] = text1[i];
            ++index1;
            if (index1 == 11) {
                index2 = i+1;
                break;
            }
        }
    }
    char money1[19] = {}, money2[19] = {};
    checkmoney(money1, text1, index2, strlen(text1));
    checkmoney(money2, text2, 0, strlen(text2));
    char* raw1 = strtok(money1, "\0");
    char* raw2 = strtok(money2, "\0");
    printf ("cpf %s\n%.2f\n", cpf, atof(raw1)+atof(raw2));
}

int main() {
    char input1[62], input2[62];
    fgets(input1, 62, stdin);
    input1[strcspn(input1, "\n")] = '\0';
    fgets(input2, 62, stdin);
    input2[strcspn(input2, "\n")] = '\0';
    check(input1, input2);

    return 0;
}