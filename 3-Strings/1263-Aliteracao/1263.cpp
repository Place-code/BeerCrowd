#include <iostream>
#include <cctype>
#include <sstream>

int alcounter (const std::string& text) {
    int counter = 0;
    bool isal = false;
    std::stringstream iss(text);
    std::string word;
    iss >> word;
    char ant = std::tolower(word[0]);
    char now = ant;
    while (iss >> word) {
        now = std::tolower(word[0]);
        if (now == ant) {
            if (!isal) {
                ++counter;
                isal = true;
            }
        }
        else {
            isal = false;
        }
        ant = now;
    }
    return counter;
}

int main() {
    std::string txt;
    while (std::getline(std::cin, txt)) {
        std::cout<<alcounter(txt)<<"\n";
    }
    return 0;
}