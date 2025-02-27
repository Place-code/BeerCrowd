#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h>

void checkmoney(std::string& money, std::string& text, int index) {
    bool checkpoint = false;
    int pindex = 0;
    for (int i = index; i < text.length(); ++i) {
        if (isdigit(text[i]) || text[i] == '.') {
            money += text[i];
            if (text[i] == '.') {
                checkpoint = true;
            }
            if (checkpoint) {
                ++pindex;
                if (pindex == 3) {
                    break;
                }
            }   
        }
    }
}

void checkall (std::string& text1, std::string& text2) {
    std::string cpf;
    int index = 0, index2 = 0;
    for (int i = 0; i < text1.length(); ++i) {
        if (isdigit(text1[i])) {
            cpf += text1[i];
            ++index;
            if (index == 11) {
                index2 = i+1;
                break;
            }
        }
    }
    std::string money1, money2;
    checkmoney(money1, text1, index2);
    checkmoney(money2, text2, 0);
    std::cout<<"cpf "<<cpf<<"\n"<<std::fixed<<std::setprecision(2)<<stod(money1)+stod(money2)<<"\n";
}

int main() {
    std::string input1, input2;
    std::getline(std::cin, input1);
    std::getline(std::cin, input2);
    checkall(input1, input2);

    return 0;
}