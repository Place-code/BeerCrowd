#include <iostream>

int main() {
    int points, quota;
    std::cin>>points>>quota;
    int ant, curr, cnt[points] = {0}, index = 0, greatest = 0;
    bool onsequence = false;
    std::cin>>ant;
    for (int i = 0; i < points-1; ++i) {
        std::cin>>curr;
        if (curr - ant <= quota) {
            onsequence = true;
        }
        else {
            onsequence = false;
            ++index;
        }
        if (onsequence) ++cnt[index];
        ant = curr;
    }
    for (int i = 0; i < points; ++i) {
        if (greatest < cnt[i]) greatest = cnt[i];
    }
    std::cout<<greatest+1<<"\n";
    
    return 0;
}