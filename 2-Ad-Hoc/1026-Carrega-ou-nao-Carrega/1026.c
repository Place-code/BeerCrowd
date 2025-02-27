#include <stdio.h>
#include <stdint.h>

unsigned sum(long long n1, long long n2) {
    return n1 ^ n2;
}

int main() {
    long long n1, n2;
    while (scanf("%lld %lld", &n1, &n2) != EOF) {
        printf("%u\n", sum(n1, n2));
    }
    return 0;
}
