#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int alcounter(char text[]) {
    int counter = 0;
    bool isal = false;
    char *pt = strtok(text, " ");
    char ant = tolower(pt[0]);
    char now = ant;
    while ((pt = strtok(NULL, " ")) != NULL) {
        now = tolower(pt[0]);
        if (ant == now) {
            if (!isal) {
                ++counter;
                isal = true;   
            }
        }
        else {
            isal = false;
        }
        ant = now;
    }
    return counter;
}

int main() {
    char txt[600];
    while (fgets(txt, 600, stdin) != NULL) {
        printf ("%d\n", alcounter(txt));
    }
    return 0;
}