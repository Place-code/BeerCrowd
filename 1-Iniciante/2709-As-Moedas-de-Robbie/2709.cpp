#include <iostream>
#include <cmath>

bool isprime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int len;
    while (std::cin>>len) {
        int coin, increment, sum = 0, coins[len];
        for (int i = 0; i < len; i++) {
            std::cin>>coin;
            coins[i] = coin;
        }
        std::cin>>increment;
        for (int i = len-1; i >= 0; i -= increment) {
            sum += coins[i];
        }
        if (isprime(sum))
            std::cout<<"You’re a coastal aircraft, Robbie, a large silver aircraft.\n";
        else
            std::cout<<"Bad boy! I’ll hit you.\n";   
    }
    return 0;
}