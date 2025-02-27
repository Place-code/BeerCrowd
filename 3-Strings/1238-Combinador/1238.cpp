#include <iostream>
#include <string>

void combine (std::string word1, std::string word2) {
    std::string combined;
    bool check1 = true, check2 = true;
    for (int i = 0; i < 52; ++i) {
        if (!check1 && !check2) {
            break;
        }
        if (check1) {
            if (word1[i] != '\0') {
                combined += word1[i];
            }
            else {
                check1 = false;
            }
        }
        if (check2) {
            if (word2[i] != '\0') {
                combined += word2[i];   
            }
            else {
                check2 = false;
            }
        }
    }
    std::cout<<combined<<"\n";
}

int main() {
    std::string input1, input2;
    int len;
    std::cin>>len;
    for (int i = 0; i < len; ++i) {
        std::cin>>input1>>input2;
        combine(input1, input2);   
    }

    return 0;
}