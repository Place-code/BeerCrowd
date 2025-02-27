#include <iostream>
#include <string>
#include <sstream>

std::string uncript(std::string& text) {
    std::stringstream iss(text);
    std::string word, message;
    while (iss >> word) {
        message += word[0];
    }
    return message;
}

int main() {
    int cases;
    std::string input;
    std::cin>>cases;
    std::cin.ignore();
    for (int i = 0; i < cases; ++i) {
        std::getline(std::cin, input);
        std::cout<<uncript(input)<<"\n";
    }

    return 0;
}