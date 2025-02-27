#include <iostream>

int numerize (char team[]) {
    if (team[0] == 82) {
        return 0;
    }
    else if (team[0] == 71) {
        return 1;
    }
    else {
        return 2;
    }
}

int main() {
    int pitch[3][2] = {{2, 1}, {0, 1}, {1, 0}};
    int cases, goals;
    char ct1[3], ct2[3];
    int t1, t2;
    std::cin>>cases;
    for (int i = 0; i < cases; ++i) {
        int teams[] = {0, 0, 0};
        std::cin>>goals;
        for (int j = 0; j < goals; ++j) {
            std::cin>>ct1>>ct2;
            t1 = numerize(ct1); t2 = numerize(ct2);
            if (pitch[t1][0] == t2) {
                ++teams[t1];
            }
            else {
                teams[t1] += 2;
            }
        }
        if (teams[0] == teams[1] && teams[1] == teams[2]) {
            std::cout<<"trempate\n";
        }
        else {
            if (teams[0] > teams[1] && teams[1] >= teams[2] || teams[0] > teams[2] && teams[2] >= teams[1]) {
                std::cout<<"red\n";
            }
            else if (teams[1] > teams[0] && teams[0] >= teams[2] || teams[1] > teams[2] && teams[2] >= teams[0]) {
                std::cout<<"green\n";
            }
            else if (teams[2] > teams[0] && teams[0] >= teams[1] || teams[2] > teams[1] && teams[1] >= teams[0]) {
                std::cout<<"blue\n";
            }
            else {
                std::cout<<"empate\n";
            }
        }
    }
    return 0;
}