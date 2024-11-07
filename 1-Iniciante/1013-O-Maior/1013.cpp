#include <iostream>
#include <iomanip>

int main() {
    
    int a, b, c;
    std::cin>>a>>b>>c;
    int maiorAB = (a+b+abs(a-b))/2;
    if (maiorAB > c) {
        std::cout<<maiorAB<<" eh o maior\n";
    }
    else {
        std::cout<<c<<" eh o maior\n";
    }
    
    return 0;
}