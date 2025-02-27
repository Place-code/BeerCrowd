#include <stdio.h>
#include <string.h>

int lowest(char number[], int len) {
    int palp = number[0]-48, index = 0, tcounter = 0;
    for (int i = 0; i < len; ++i) {
        if (number[i]-48 < palp) {
            palp = number[i]-48;
            index = i;
        }
        if (number[i] == 't') {
            ++tcounter;
        }
    }
    number[index] = 't';
    if (tcounter == len) {
        palp = -1;
    }
    return palp;
}

int zcounter (char number[], int len) {
    int counter = 0;
    for (int i = 0; i < len; ++i) {
        if (number[i] == '0') {
            number[i] = 't';
            ++counter;
        }
    }
    return counter;
}

int main() {
    int cases, ctrl, len, zeroes;
    char txt[2000];
    scanf("%d", &cases);
    for (int i = 0; i < cases; ++i) {
        scanf("%s", txt);
        len = strlen(txt);
        zeroes = zcounter(txt, len);
        printf ("%d", lowest(txt, len));
        for (int i = 0; i < zeroes; ++i) {
            printf ("0");
        }
        while (1) {
            ctrl = lowest(txt, len);
            if (ctrl != -1) {
                printf ("%d", ctrl);   
            }
            else {
                break;
            }
        }
        printf ("\n");
    }

    return 0;
}