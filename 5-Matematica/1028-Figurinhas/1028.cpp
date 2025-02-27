#include <iostream>

int mdc(int maior, int menor) {
    int mod = maior % menor;
    while (mod != 0) {
        maior = menor;
        menor = mod;
        mod = maior % menor;
    }
    return menor;
}

int main() {
    int len, f1, f2;
    std::cin>>len;
    for (int i = 0; i < len; ++i) {
        std::cin>>f1>>f2;
        if (f1 > f2) {
            std::cout<<mdc(f1, f2)<<"\n";
        }
        else {
            std::cout<<mdc(f2, f1)<<"\n";
        }
    }

    return 0;
}