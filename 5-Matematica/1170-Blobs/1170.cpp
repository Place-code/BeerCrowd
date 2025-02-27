#include <iostream>

int main() {
    
    int len;
    float num;
    std::cin>>len;
    for (int i = 0; i <+ len; ++i) {
        int qt = 0;
        std::cin>>num;
        while (num > 1) {
            num -= num/2;
            ++qt;
        }
        std::cout<<qt<<" dias\n";   
    }

    return 0;
}