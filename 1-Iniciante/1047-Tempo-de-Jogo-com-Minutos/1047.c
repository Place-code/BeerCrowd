#include <stdio.h>

int main() {
    int time[4];
    scanf ("%d %d %d %d", &time[0], &time[1], &time[2], &time[3]);
    if (time[1] > time[3]) {
        time[2] -= 1;
        time[3] += 60;
    }
    if (time[0] < time[2] || time[0] == time[2] && time[1] < time[3]) {
        printf ("O JOGO DUROU %d HORA(S) E %d MINUTOS(S)\n", time[2] - time[0], time[3] - time[1]);
    }
    else {
        printf ("O JOGO DUROU %d HORA(S) E %d MINUTOS(S)\n", time[2] - time[0] + 24, time[3] - time[1]);
    }
    return 0;
}