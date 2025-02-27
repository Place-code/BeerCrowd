#include <stdio.h>

int flavious (int n, int k) {
    int i = 1, ans = 0;
    while (i <= n) {
        ans = (ans + k) % i;
        ++i;
    }
    return ans+1;
}

int main() {
    int len, num, jump;
    scanf("%d", &len);
    for (int i = 1; i <= len; ++i) {
        scanf ("%d %d", &num, &jump);
        printf ("Case %d: %d\n", i, flavious(num, jump));
    }
    return 0;
}
