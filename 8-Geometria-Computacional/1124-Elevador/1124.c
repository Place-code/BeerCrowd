#include <stdio.h>
#include <math.h>

int main() {
    int width, height, r1, r2;
    while (1) {
        scanf ("%d %d %d %d", &width, &height, &r1, &r2);
        if (width == 0 && height == 0 && r1 == 0 && r2 == 0) break;
        (r1*2 <= width && r2*2 <= width && r1*2 <= height && r2*2 <= height && sqrt(pow(height-r1-r2, 2)+pow(width-r1-r2, 2)) >= r1+r2) ? printf ("S\n") : printf ("N\n");   
    }
    return 0;
}