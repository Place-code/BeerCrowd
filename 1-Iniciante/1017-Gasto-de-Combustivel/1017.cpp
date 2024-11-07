#include <iostream>
#include <iomanip>

int main() {
    
    int h, km;
    std::cin>>h>>km;
    std::cout<<std::fixed<<std::setprecision(3)<<(float)h*km/12<<"\n";
    
    return 0;
}