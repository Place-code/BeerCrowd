#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

int main() {
    int people, dose = 1, index;
    float bottle, bowl;
    std::vector<std::string> contestants;
    std::cin>>people>>bottle>>bowl;
    contestants.resize(people);
    for (int i = 0; i < people; ++i) {
        std::cin>>contestants[i];
    }
    while (bottle-bowl*dose > 0) {
        ++dose;
    }
    --dose;
    std::cout<<std::setprecision(1)<<contestants.at(dose%people)<<" "<<bottle-bowl*dose<<"\n";
    return 0;
}