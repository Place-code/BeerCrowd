#include <stdio.h>

int main() {
    int r, gas;
    scanf ("%d %d", &r, &gas);
    printf ("%d\n",(int) (gas / ((4*3.1415*r*r*r)/3)));
    return 0;
}