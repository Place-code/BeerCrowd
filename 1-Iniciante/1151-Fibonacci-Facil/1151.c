# include <stdio.h>

int main() {

    int atual, ant = 1, antsuc = 0, analog;
    scanf ("%d", &atual);
    analog = atual - 2;
    printf ("0 1 ");
    for (int i = 1; i <= analog; i++) {
        atual = ant + antsuc;
        antsuc = ant;
        ant = atual;
        if (i == analog) {
            printf ("%d\n", atual);
        }
        else {
            printf ("%d ", atual);
        }
    }

    return 0;
}