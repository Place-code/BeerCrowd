#include <iostream>

int main() {
    
    int led[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, index, sum;
    char input[101];
    std::cin>>index;
    for (int i = 0; i < index; ++i) {
        sum = 0;
        std::cin>>input;
        for (int q = 0; q <= 101; ++q) {
            if (input[q] == '\0')
                break;
            sum += led[((int)input[q])-48];
        }
        std::cout<<sum<<" leds\n";
    }
    return 0;
}