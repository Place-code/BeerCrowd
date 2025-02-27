#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

bool tautocheck(std::string& text) {
    std::istringstream iss(text);
    std::string word;
    iss >> word;
    char letter = std::tolower(word[0]);
    bool istauto = true;
    while (iss >> word) {
        if (std::tolower(word[0]) != letter) {
            istauto = false;
            break;
        }
    }
    return istauto;
}

int main() {
    std::string txt;
    while (true) {
        std::getline(std::cin, txt);
        if (txt[0] == '*') {
            break;
        }
        if (tautocheck(txt)) {
            std::cout<<"Y\n";
        }
        else {
            std::cout<<"N\n";
        }
    }
    
    return 0;
}