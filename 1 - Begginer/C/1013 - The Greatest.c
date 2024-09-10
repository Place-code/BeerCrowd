#include <stdio.h>
 
int main() {
 
    int a, b, c, ab, m;

    scanf("%d %d %d", &a, &b, &c);

    ab = (a + b + abs(a - b)) / 2;
    m = (ab + c + abs(ab - c)) / 2;

    printf("%d eh o maior\n", m);

    return 0;
}