#include <iostream>
#include <iomanip>

int main() {
    
    int code1, code2, n1, n2;
    float v1, v2;
    std::cin>>code1>>n1>>v1>>code2>>n2>>v2;
    std::cout<<std::fixed<<std::setprecision(2)<<"VALOR A PAGAR: R$ "<<n1*v1+n2*v2<<"\n";
    return 0;
}