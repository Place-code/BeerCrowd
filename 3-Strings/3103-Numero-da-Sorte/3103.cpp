#include <iostream>
#include <string>

int lowest (std::string& number, int len) {
    int palp = number[0]-48, index = 0, tcounter = 0;
    for (int i = 0; i < len; ++i) {
        if (number[i]-48 < palp) {
            palp = number[i]-48;
            index = i;
        }
        else if (number[i] == 't') ++tcounter;
    }
    number[index] = 't';
    if (tcounter == len) return -1;
    return palp;
}

int zcounter (std::string& number) {
    int counter = 0, i = 0;
    for (char ch : number) {
        if (ch == '0') {
            ++counter;
            number[i] = 't';   
        }
        ++i;
    }
    return counter;
}

int main() {
    int cases, zeroes, len, evidence;
    std::string txt;
    std::cin>>cases;
    for (int i = 0; i < cases; ++i) {
        std::cin>>txt;
        len = txt.length();
        zeroes = zcounter(txt);
        std::cout<<lowest(txt, len);
        for (int i = 0; i < zeroes; ++i) std::cout<<"0";
        while (1) {
            evidence = lowest(txt, len);
            if (evidence == -1) break;
            std::cout<<evidence;   
        }
        std::cout<<"\n";
    }
    return 0;
}