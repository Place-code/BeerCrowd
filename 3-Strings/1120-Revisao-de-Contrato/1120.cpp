#include <iostream>

const int len = 101;

char* correction(char term[2], char text[len], char newtext[len]) {
    int newindex = 0;
    for (int index=0; index<len; ++index) {
        if (text[index] == '\0') {
            newtext[index] = '\0';
            break;
        }
        if (text[index] != term[0]) {
            newtext[newindex] = text[index];
            ++newindex;
        }
    }
    return newtext;
}
char* justify(char text[len], char newtext[len]) {
    int index = 0;
    bool oncheck = true;
    for (int i = 0; i <= len; ++i) {
        if (text[i] != '0') {
            oncheck = false;
            newtext[index] = text[i];
            ++index;   
        }
        else if (text[i] == '0' && oncheck == false) {
            newtext[index] = text[i];
            ++index;   
        }
    }
    return newtext;
}
int main() {
    char correct[2], txt[len];
    while (true) {
        std::cin>>correct>>txt;
        if (correct[0] == '0' && txt[0] == '0') {
            break;
        }
        char newtext[len] = {};
        char* corrected = correction(correct, txt, newtext);
        if (corrected[0] == '0')
            corrected = justify(corrected, newtext);
        if (corrected[0] == '\0')
            std::cout<<"0\n";
        else
            std::cout<<corrected<<"\n";
    }
    return 0;
}