#include <iostream>

int main() {
    int ncities, nfrontiers, qnt = 0, city1, city2;
    std::cin>>ncities>>nfrontiers;
    bool cities[ncities];
    for (int i = 0; i < ncities; ++i) {
        cities[i] = false;
    }
    for (int i = 0; i < nfrontiers; ++i) {
        std::cin>>city1>>city2;
        if (!cities[city1-1] && !cities[city2-1]) {
            ++qnt;
        }
        cities[city1-1] = true;
        cities[city2-1] = true;
    }
    for (int i = 0; i < ncities; ++i) {
        if (!cities[i]) ++qnt;
    }
    std::cout<<qnt<<"\n";
    return 0;
}