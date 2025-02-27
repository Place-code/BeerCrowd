#include <iostream>

int flavious(int num, int jump) {
    int i = 1, ans = 0;
    while (i <= num) {
        ans = (ans + jump) % i;
        ++i;
    }
    return ans+1;
}

int main() {
    int len, n, k;
    std::cin>>len;
    for (int i = 1; i <= len; ++i) {
        std::cin>>n>>k;
        std::cout<<"Case "<<i<<": "<<flavious(n, k)<<"\n";
    }

    return 0;
}