#include <iostream>

int main() {
    
    int times[4];
    std::cin>>times[0]>>times[1]>>times[2]>>times[3];
    if (times[1] > times[3]) {
        times[2] -= 1;
        times[3] += 60;   
    }
    if (times[0] < times[2] || times[0] == times[2] && times[1] < times[3])
        std::cout<<"O JOGO DUROU "<<times[2]-times[0]<<" HORA(S) E "<<times[3]-times[1]<<" MINUTO(S)\n";
    else
        std::cout<<"O JOGO DUROU "<<times[2]-times[0]+24<<" HORA(S) E "<<times[3]-times[1]<<" MINUTO(S)\n";
        
    return 0;
}