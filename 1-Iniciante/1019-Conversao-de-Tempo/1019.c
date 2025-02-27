#include <stdio.h>

int main() {
    
    int s, h = 0, m;
    scanf ("%d", &s);
    m = s / 60;
    s = s - 60 * (s / 60);
    if (m > 60) {
        h = m / 60;
        m = m - 60 * (m / 60);
    }
    printf ("%d:%d:%d\n", h, m, s);
    
    return 0;
}