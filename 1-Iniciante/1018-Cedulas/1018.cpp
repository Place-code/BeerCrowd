#include <iostream>

int main() {
    
    int bill;
    int values[] = {100, 50, 20, 10, 5, 2, 1};
    std::cin>>bill;
    std::cout<<bill<<"\n";
    for (int i = 0; i <= 6; ++i) {
        std::cout<<(int)bill/values[i]<<" nota(s) de R$ "<<values[i]<<",00\n";   
        bill -= values[i] * (bill/values[i]);
    }
    
    return 0;
}