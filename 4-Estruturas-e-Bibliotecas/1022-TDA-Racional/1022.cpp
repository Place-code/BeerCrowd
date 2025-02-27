#include <cstdio>
#include <cmath>

void mdc(int n1, int d1) {
    int divcom = 1;
    if (n1 < d1 && n1 != 0) {
        for (int i = abs(n1); i > 1; --i) {
            if (n1 % i == 0 && d1 % i == 0) {
                divcom = i;
                break;
            }
        }
    }
    else {
        for (int i = abs(d1); i > 1; --i) {
            if (n1 % i == 0 && d1 % i == 0) {
                divcom = i;
                break;
            }
        }
    }
    printf ("%d/%d = %d/%d\n", n1, d1, n1/divcom, d1/divcom);
}

int main() {
    int cases, n1, d1, n2, d2;
    char op[2];
    scanf ("%d", &cases);
    for (int i = 0; i < cases; ++i) {
        scanf ("%d / %d %s %d / %d", &n1, &d1, op, &n2, &d2);
        if (op[0] == '+') {
            mdc((n1*d2+n2*d1), (d1*d2));
        }
        else if (op[0] == '-') {
            mdc((n1*d2-n2*d1), (d1*d2));
        }
        else if (op[0] == '*') {
            mdc((n1*n2), (d1*d2));
        }
        else if (op[0] == '/') {
            mdc((n1*d2), (n2*d1));
        }
    }
    return 0;
}