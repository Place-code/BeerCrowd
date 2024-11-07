#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    
    char txt[6];
    int mth, day;
    fgets (txt, 6, stdin);
    char *pt = strtok(txt, "/");
    day = atoi(pt);
    pt = strtok(NULL, " ");
    mth = atoi(pt);
   if (mth == 3) {
        if (day >= 20) {
            printf ("peixes\n");   
        }
        else {
            printf ("aries\n");   
        }
    }
    else if (mth == 4) {
        if (day <= 20) {
            printf ("aries\n");
        }
        else {
            printf ("touro\n");
        }
    }
    else if (mth == 5) {
        if (day <= 20) {
            printf ("touro\n");
        }
        else {
            printf ("gemeos\n");
        }
    }
    else if (mth == 6) {
        if (day <= 20) {
            printf ("gemeos\n");
        }
        else {
            printf ("cancer\n");
        }
    }
    else if (mth == 7) {
        if (day <= 22) {
            printf ("cancer\n");
        }
        else {
            printf ("leao\n");
        }
    }
    else if (mth == 8) {
        if (day <= 22) {
            printf ("leao\n");
        }
        else {
            printf ("virgem\n");
        }
    }
    else if (mth == 9) {
        if (day <= 22) {
            printf ("virgem\n");
        }
        else {
            printf ("libra\n");
        }
    }
    else if (mth == 10) {
        if (day <= 22) {
            printf ("libra\n");
        }
        else {
            printf ("escorpiao\n");
        }
    }
    else if (mth == 11) {
        if (day <= 21) {
            printf ("escorpiao\n");
        }
        else {
            printf ("sagitario\n");
        }
    }
    else if (mth == 12) {
        if (day <= 21) {
            printf ("sagitario\n");   
        }
        else {
            printf ("capricornio\n");
        }
    }
    else if (mth == 1) {
        if (day <= 18) {
            printf ("capricornio\n");
        }
        else {
            printf ("aquario\n");
        }
    }
    else if (mth == 2) {
        if (day <= 18) {
            printf ("aquario\n");
        }
        else {
            printf ("peixes\n");
        }
    }
    
    return 0;
}