#include <iostream>

int main() {
    int cases, dx, dy, hx, hy;
    while (1) {
        std::cin>>cases;
        if (cases == 0) break;
        std::cin>>dx>>dy;
        for (int i = 0; i < cases; ++i) {
            std::cin>>hx>>hy;
            if (hx == dx || hy == dy) {
                std::cout<<"divisa\n";
            }
            else {
                if (hx > dx) {
                    if (hy > dy) {
                        std::cout<<"NE\n";
                    }
                    else {
                        std::cout<<"SE\n";
                    }
                }
                else {
                    if (hy > dy) {
                        std::cout<<"NO\n";
                    }
                    else {
                        std::cout<<"SO\n";
                    }
                }   
            }
        }
    }
    return 0;
}