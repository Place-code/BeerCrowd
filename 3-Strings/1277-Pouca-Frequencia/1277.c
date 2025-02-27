#include <stdio.h>
#include <string.h>

void check (char stulist[], char pres[], char* reject) {
    char* student = strtok(stulist, " ");
    int nclass = 0, attended = 0, lenreject = 0, lenpres = 0, cp = 0;
    while (student != NULL) {
        for (int i = lenpres; i <= 5051; ++i) {
            if (pres[i] == ' ' || pres[i] == '\0') {
                break;
            }
            if (pres[i] != 'M') {
                ++nclass;
            }
            if (pres[i] == 'P') {
                ++attended;
            }
            ++cp;
        }
        lenpres += cp + 1;
        if ((float)attended/nclass < 0.75) {
            strcpy(&reject[lenreject], student);
            lenreject += strlen(student);
            reject[lenreject++] = ' ';
        }
        cp = 0;
        nclass = 0;
        attended = 0;
        student = strtok(NULL, " ");
    }
    reject[lenreject-1] = '\0';
}

int main() {
    int cases, stulen;
    scanf("%d", &cases);
    getchar();
    char students[5051], pres[5051];
    for (int i = 0; i < cases; ++i) {
        char rejected[5051] = {};
        scanf ("%d", &stulen);
        getchar();
        fgets(students, 5051, stdin);
        fgets(pres, 5051, stdin);
        students[strcspn(students, "\n")] = '\0';
        pres[strcspn(pres, "\n")] = '\0';
        check(students, pres, rejected);
        printf ("%s\n", rejected);
    }
    return 0;
}