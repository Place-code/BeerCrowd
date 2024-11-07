#include <iostream>
#include <cstring>
#include <string>

int main() {
    std::string txt;
    while (std::getline(std::cin, txt)) {
        char newtxt[50] = {};
        int index = 0, counter = 0;
        for (int i = 0; i < txt.length(); ++i) {
            if (txt[i] != ' ') {
                if (counter % 2 == 0) {
                    newtxt[index] = char((int) (txt[i] >= 'a' && txt[i] <= 'z' ? (txt[i] - 32) : txt[i]));
                }
                else{
                    newtxt[index] = char((int) (txt[i] >= 'A' && txt[i] <= 'Z' ? (txt[i] + 32) : txt[i]));
                }
                ++counter;
            }
            else {
                newtxt[index] = txt[i];
            }
            ++index;
        }
        std::cout<<newtxt<<"\n";   
    }
    
    return 0;
}