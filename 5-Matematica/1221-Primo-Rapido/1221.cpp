#include <iostream>
#include <math.h>

bool prime(int num) {
    bool prime = true;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            prime = false;
            break;
        }
    }
    return prime;
}

int main() {
    int n, num;
    std::cin>>n;
    for (int i = 0; i < n; ++i) {
        std::cin>>num;
        if (prime(num)) {
            std::cout<<"Prime\n";
        }
        else {
            std::cout<<"Not Prime\n";
        }
    }

    return 0;
}