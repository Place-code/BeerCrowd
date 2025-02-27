#include <iostream>

int main() {
    int nbanks, nfare, d, c, v;
    while (1) {
        std::cin>>nbanks>>nfare;
        if (nbanks == 0 && nfare == 0) break;
        int banks[nbanks];
        for (int i = 0; i < nbanks; ++i) std::cin>>banks[i];
        for (int i = 0; i < nfare; ++i) {
            std::cin>>d>>c>>v;
            banks[d-1] -= v;
            banks[c-1] += v;
        }
        bool able = true;
        for (int i = 0; i < nbanks; ++i) {
            if (banks[i] < 0) {
                able = false;
                break;
            }
        }
        if (able) {
            std::cout<<"S\n";
        }
        else {
            std::cout<<"N\n";
        }
    }
    return 0;
}