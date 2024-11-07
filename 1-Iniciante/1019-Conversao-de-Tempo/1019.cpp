#include <iostream>

int main() {
    
    int times;
    std::cin>>times;
    std::cout<<times/3600<<":";
    times -= 3600 * (times/3600);
    std::cout<<times/60<<":";
    times -= 60 * (times/60);
    std::cout<<times<<"\n";
    
    return 0;
}