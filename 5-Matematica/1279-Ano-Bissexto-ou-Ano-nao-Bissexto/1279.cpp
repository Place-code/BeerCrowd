#include <iostream>
#include <string>

int main() {
    std::string number;
    bool pres = false, isleap, ishulukulu;
    int ppar = 0, pimpar = 0, len;
    while (std::cin>>number) {
        if (pres) {
            std::cout<<"\n";
        }
        else {
            pres = true;
        }
        len = number.length();
        for (int i = 0; i < len; ++i) {
            if (i % 2 == 0) {
                ppar += number[i]-48;
            }
            else {
                pimpar += number[i]-48;
            }
        }
        isleap = false, ishulukulu = false;
        if (((((number[len-2]-48)*10 + (number[len-1]-48)) % 4 == 0) && (number[len-2] != '0' || number[len-1] != '0')) || ((number[len-2] == '0' && number[len-1] == '0') && ((((number[len-4]-48)*10 + (number[len-3]-48)) * 100) % 400 == 0))) {
            std::cout<<"This is leap year.\n";
            isleap = true;
        }
        if (((ppar + pimpar) % 3 == 0) && (number[len-1] == '0' || number[len-1] == '5')) {
            std::cout<<"This is huluculu festival year.\n";
            ishulukulu = true;
        }
        if ((ppar - pimpar) % 11 == 0 && isleap) {
            std::cout<<"This is bulukulu festival year.\n";
        }
        else if (!isleap && !ishulukulu) {
            std::cout<<"This is an ordinary year.\n";
        }
        ppar = 0;
        pimpar = 0;
    }
    return 0;
}