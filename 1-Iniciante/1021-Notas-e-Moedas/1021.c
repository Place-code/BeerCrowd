# include <stdio.h>

int main() {

    int dim[12] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};
    int i, r, cent;
    scanf ("%d.%d", &r, &cent);
    r = 100 * r + cent;
    printf ("NOTAS:\n");    
    for (i = 0; i <= 5; i++) {
        printf ("%d nota(s) de R$ %.2lf\n", r / dim[i], dim[i] / 100.00);
        r %= dim[i];
    }
    printf ("MOEDAS:\n");
    for (i = 6; i <= 11; i++) {
        printf ("%d moeda(s) de R$ %.2lf\n", r / dim[i], dim[i] / 100.00);
        r %= dim[i];
    }
    return 0;
}