#include <iostream>
#include <string>

int main() {
    std::string txt;
    bool icheck = false, bcheck = false;
    while (std::getline(std::cin, txt)) {
        for (char ch : txt) {
            if (ch == '_') {
                if (icheck) {
                    std::cout<<"</i>";
                    icheck = false;
                }
                else {
                    std::cout<<"<i>";
                    icheck = true;
                }
            }
            else if (ch == '*') {
                if (bcheck) {
                    std::cout<<"</b>";
                    bcheck = false;
                }
                else {
                    std::cout<<"<b>";
                    bcheck = true;
                }
            }
            else {
                std::cout<<ch;
            }
        }
        std::cout<<"\n";
    }
    
    return 0;
}