#include <iostream>
#include <string>

int main() {
    bool alpha[26];
    int cases, counter;
    std::string text;
    std::cin>>cases;
    std::cin.ignore();
    for (int i = 0; i < cases; ++i) {
        for (int q = 0; q < 26; ++q) {
            alpha[q] = false;
        }
        std::getline(std::cin, text);
        for (char ch : text) {
            if (ch != ' ' && ch != ',') {
                alpha[ch-97] = true;
            }
        }
        counter = 0;
        for (int q = 0; q < 26; ++q) {
            if (alpha[q]) {
                ++counter;
            }
        }
        if (counter == 26) {
            std::cout<<"frase completa\n";
        }
        else if (counter >= 13) {
            std::cout<<"frase quase completa\n";
        }
        else {
            std::cout<<"frase mal elaborada\n";
        }
    }
    return 0;
}