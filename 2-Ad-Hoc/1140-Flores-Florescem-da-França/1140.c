#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    for (;;) {
        char txt[1050], comp[2];
        fgets (txt, 1050, stdin);
        if (txt[0] == '*') {
            break;
        }
        bool let = true;
        comp[0] = txt[0];
        if (comp[0] < 97) {
            comp[0] += 32;
        }
        char *pt = strtok(txt, " ");
        while (pt != NULL) {
            if (pt[0] < 97) {
                pt[0] += 32;
            }
            if (pt[0] != comp[0]) {
                let = false;
                break;
            }
            pt = strtok(NULL, " ");
        }
        if (let == true) {
            printf ("Y\n");
        }
        else {
            printf ("N\n");
        }   
    }
    return 0;
}