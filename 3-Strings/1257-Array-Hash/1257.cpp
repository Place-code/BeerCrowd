#include <iostream>

int main() {
    int cases, el, sum = 0;
    char text[51];
    std::cin>>cases;
    for (int i = 0; i < cases; ++i) {
        std::cin>>el;
        for (int q = 0; q < el; ++q) {
            std::cin>>text;
            for (int z = 0; z <= 51; ++z) {
                if (text[z] == '\0') {
                    break;
                }
                sum += (text[z] - 65) + q + z;
            }
        }
        std::cout<<sum<<"\n";
        sum = 0;
    }

    return 0;
}