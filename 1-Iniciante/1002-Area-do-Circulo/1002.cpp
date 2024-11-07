#include <iostream>
#include <math.h>
#include <iomanip>

int main() {
    
    double r;
    std::cin>>r;
    std::cout<<std::fixed<<std::setprecision(4)<<"A="<<pow(r, 2)*3.14159<<"\n";
    
    return 0;
}