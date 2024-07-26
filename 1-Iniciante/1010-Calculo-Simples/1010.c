#include <stdio.h>

int main() {

    int cod, qnt;
    float num;
    float valor[4] = {0, 0, 0, 0};
    for (int i = 0; i < 2; i++) {
    scanf ("%d %d %f", &cod, &qnt, &num);
    if (valor[0] == 0.0 && valor[1] == 0.0) {
        valor[0] = qnt;
        valor[1] = num;
    }
    else {
        valor[2] = qnt;
        valor[3] = num;
    }
    }
    printf ("VALOR A PAGAR: R$ %.2f\n", valor[0] * valor[1] + valor[2] * valor[3]);
    
    return 0;
}