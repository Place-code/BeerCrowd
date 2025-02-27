#include <cstdio>

int main() {
    float media = 0, input;
    for (int i = 0; i < 3; ++i) {
        scanf("%f", &input);
        media += input * (i+2);
    }
    scanf("%f", &input);
    media += input;
    media /= 10;
    printf ("Media: %.1f\n", media);
    if (media >= 5 && media <= 6.9) {
        printf("Aluno em exame.\n");
        scanf("%f", &input);
        printf ("Nota do exame: %.1f\n", input);
        media = (media + input) / 2;
        if (media >= 5) {
            printf ("Aluno aprovado.\n");
        }
        else {
            printf ("Aluno reprovado.\n");
        }
        printf ("Media final: %.1f\n", media);
    }
    else if (media >= 7) {
        printf ("Aluno aprovado.\n");
    }
    else {
        printf ("Aluno reprovado.\n");
    }
    return 0;
}