#include <iostream>
#include <string>
#include <algorithm>

std::string right(const std::string& text) {
    std::string newtext;
    for (char ch : text) {
        if (ch == '\0') {
            ch = '\0';
            break;
        }
        newtext += (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') ? char((int)ch + 3) : ch;
    }
    return newtext;
}

std::string left (const std::string& text, int len) {
    std::string newtext = text;
    for (int i = len / 2; i < len; ++i) {
        newtext[i] = (i >= len / 2) ? char((int)newtext[i] - 1) : newtext[i];
    }
    return newtext;
}

int main() {
    int n;
    std::string txt;
    std::cin>>n;
    std::cin.ignore();
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, txt);
        txt = right(txt);
        std::reverse(txt.begin(), txt.end());
        txt = left(txt, txt.length());
        std::cout<<txt<<std::endl;
    }

    return 0;
}