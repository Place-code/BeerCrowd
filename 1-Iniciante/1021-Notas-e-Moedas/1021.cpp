#include <iostream>
#include <iomanip>

int main() {
    
    float value;
    int values[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};
    std::cin>>value;
    int bill = value*100;
    std::cout<<"NOTAS:\n";
    for (int i = 0; i <= 5; ++i) {
        std::cout<<(int)bill/values[i]<<" nota(s) de R$ "<<values[i]/100<<".00\n";
        bill %= values[i];
    }
    std::cout<<"MOEDAS:\n";
    for (int i = 6; i <= 11; ++i) {
        std::cout<<(int)bill/values[i]<<std::fixed<<std::setprecision(2)<<" moeda(s) de R$ "<<values[i]/100.00<<"\n";
        bill %= values[i];
    }
    
    return 0;
}