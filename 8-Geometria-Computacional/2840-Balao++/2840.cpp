#include <iostream>

int main() {
    int r, gas;
    std::cin>>r>>gas;
    std::cout<<(int) (gas / ((4*3.1415*r*r*r)/3))<<"\n";
    return 0;
}