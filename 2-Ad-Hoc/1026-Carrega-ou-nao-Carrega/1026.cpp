#include <cstdio>
#include <cstdint>

unsigned sum(int32_t n1, int32_t n2) {
    return n1 ^ n2;
}

int main() {
    int32_t n1, n2;
    while (scanf("%d %d", &n1, &n2) != EOF) {
        printf("%u\n", sum(n1, n2));
    }
    return 0;
}
