#include <stdio.h>

int main() {

    double flt, num, cutoff;
    while (scanf ("%lf %lf", &num, &cutoff) != EOF) {
        flt = num - (int) num;
        int analog = (int) num;
        if (flt >= cutoff && flt != 0) {
            printf ("%d\n", analog + 1);
        }
        else {
            printf ("%d\n", analog);
        }
    }

    return 0;
}