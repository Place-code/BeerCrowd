#include <iostream>
#include <iomanip>
#include <math.h>

int main() {
    
    double a, b, c;
    std::cin>>a>>b>>c;
    double dt = b*b- 4*a*c;
    if (dt < 0 || a == 0) {
        std::cout<<"Impossivel calcular"<<std::endl;
    }
    else {
        std::cout<<std::fixed<<std::setprecision(5);
        std::cout<<"R1 = "<<(-b+sqrt(dt))/(2*a)<<"\n";
        std::cout<<"R2 = "<<(-b-sqrt(dt))/(2*a)<<"\n";
    }
    return 0;
}