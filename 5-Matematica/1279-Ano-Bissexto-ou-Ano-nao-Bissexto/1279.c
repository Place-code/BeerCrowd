#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char *year = (char*)malloc(2001 * sizeof(char));
    bool pres = false, test, test2;
    while ((fgets(year, 2001, stdin) != NULL)) {
        if (pres) {
            printf ("\n");
        }
        else {
            pres = true;
        }
        int cont[7] = {0}; // ppar, pimpar, sn, uni, dez, cent, centmil
        for (int i = 0; i <= 2000; ++i) {
            if (isdigit(year[i]) != 0) {
                if ((i + 1) % 2 == 0) {
                    cont[0] += year[i] - 48;
                }
                else {
                    cont[1] += year[i] - 48;
                }
                cont[2] += year[i] - 48;
            }
            else {
                cont[3] = (year[i - 1] - 48);
                cont[4] = (year[i - 2] - 48);
                cont[5] = (year[i - 3] - 48);
                cont[6] = (year[i - 4] - 48);
                break;
            }
        }
        test = false, test2 = false;
        if (((10 * cont[4] + cont[3]) % 4 == 0 && (cont[3] != 0 || cont[4] != 0)) || (cont[3] == 0 && cont[4] == 0 && (((10 * cont[6] + cont[5]) * 100) % 400 == 0))) {
            printf ("This is leap year.\n");
            test = true;
        }
        if ((cont[3] == 5 || cont[3] == 0) && (cont[2] % 3 == 0)) {
            printf ("This is huluculu festival year.\n");
            test2 = true;
        }
        if (test == true && (cont[3] == 5 || cont[3] == 0) && ((cont[0] - cont[1]) % 11 == 0 || cont[0] - cont[1] == 0)) {
            printf ("This is bulukulu festival year.\n");
        }
        else if (test == false && test2 == false) {
            printf ("This is an ordinary year.\n");
        }
    }
    return 0;
}