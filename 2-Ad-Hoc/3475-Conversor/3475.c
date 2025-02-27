#include <stdio.h>

int main() {
    char inp[7];
    int num;
    scanf ("%s", inp);
    if ((int)inp[0] > 97) {
        if (inp[0] == 'z') {
            printf ("0\n");
        }
        else if (inp[0] == 'u') {
            printf ("1\n");
        }
        else if (inp[0] == 'd') {
            printf ("2\n");
        }
        else if (inp[0] == 't') {
            printf ("3\n");
        }
        else if (inp[0] == 'q') {
            printf ("4\n");
        }
        else if (inp[0] == 'c') {
            printf ("5\n");
        }
        else if (inp[0] == 's') {
            if (inp[2] == 'i') {
                printf ("6\n");   
            }
            else {
                printf ("7\n");
            }
        }
        else if (inp[0] == 'o') {
            printf ("8\n");
        }
        else {
            printf ("9\n");
        }
    }
    else {
        num = (int)inp[0]-48;
        if (num == 0) {
            printf ("zero\n");
        }
        else if (num == 1) {
            printf ("um\n");
        }
        else if (num == 2) {
            printf ("dois\n");
        }
        else if (num == 3) {
            printf ("tres\n");
        }
        else if (num == 4) {
            printf ("quatro\n");
        }
        else if (num == 5) {
            printf ("cinco\n");
        }
        else if (num == 6) {
            printf ("seis\n");
        }
        else if (num == 7) {
            printf ("sete\n");
        }
        else if (num == 8) {
            printf ("oito\n");
        }
        else {
            printf ("nove\n");
        }
    }
}