#include <iostream>
#include <cmath>

int main() {
    int r1, r2, c1[2], c2[2];
    while (std::cin>>r1>>c1[0]>>c1[1]>>r2>>c2[0]>>c2[1]) {
        (sqrt((pow(c1[0]-c2[0], 2) + pow(c1[1]-c2[1], 2))) + r2 <= r1) ? std::cout<<"RICO\n" : std::cout<<"MORTO\n";
    }
    return 0;
}