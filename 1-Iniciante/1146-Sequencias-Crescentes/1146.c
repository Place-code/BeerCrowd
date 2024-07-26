#include <stdio.h>
#include <stdbool.h>

int main() {
    
    int n;
    while (true) {
        scanf ("%d", &n);
        if (n == 0) {
            printf ("");
            break;
        }
        for (int i = 1; i <= n; i++) {
            if (i == n) {
                printf ("%d\n", i);
            }
            else {
                printf ("%d ", i);
            }
        }
    }
    
    return 0;
}