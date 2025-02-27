#include <iostream>

int main() {
    int times[4];
    while (true) {
        std::cin>>times[0]>>times[1]>>times[2]>>times[3];
        if (times[0] == 0 && times[1] == 0 && times[2] == 0 && times[3] == 0) {
            break;
        }
        if (times[3] < times[1]) {
            --times[2];
            times[3] += 60;
        }
        if (times[2] < times[0]) {
            std::cout<<(times[2]+24-times[0])*60+times[3]-times[1]<<"\n";
        }
        else {
            std::cout<<(times[2]-times[0])*60+times[3]-times[1]<<"\n";
        }   
    }
    
    return 0;
}