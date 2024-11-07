#include <iostream>
#include <string>

std::string uncript(const std::string& text, int justify) {
    std::string newtext;
    for (char ch : text) {
        if (ch - justify < 'A') {
            newtext += char((int) ch - justify + 26);
        }
        else {
            newtext += char((int) ch - justify);   
        }
    }
    return newtext;
}

int main() {
    
    std::string txt;
    int n, justify;
    std::cin>>n;
    std::cin.ignore();
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, txt);
        std::cin>>justify;
        std::cin.ignore();
        std::cout<<uncript(txt, justify)<<"\n";
    }
    
    return 0;
}