# include <stdio.h>

int main() {

    double a, b, c, d, m;
    scanf ("%lf %lf %lf %lf", &a, &b, &c, &d);
    m = (a * 2 + b * 3 + c * 4 + d) / 10;
    printf ("Media: %.1lf\n", m);
    if (m >= 7) {
        printf ("Aluno aprovado.\n");
    }
    else if (m < 5) {
        printf ("Aluno reprovado.\n");
    }
    else if (m >= 5 && m <= 6.9) {
        printf ("Aluno em exame.\n");
        scanf ("%lf", &a);
        printf ("Nota do exame: %.1lf\n", a);
        m = (m + a) / 2;
        if (m >= 5) {
            printf ("Aluno aprovado.\n");
        }
        else {
            printf ("Aluno reprovado.\n");
        }
        printf ("Media final: %.1lf\n", m);
    }

    return 0;
}