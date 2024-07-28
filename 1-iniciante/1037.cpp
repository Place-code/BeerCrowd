#include <iostream>
// 
int main(){
    float x;
    std::string prin;
    std::cin>>x;
    (x<0|x>100)?prin="0":(x<=25)?prin="[0,25]":(x<=50)?prin="(25,50]":(x<=75)?prin="(50,75]":(x<=100)?prin="(75,100]":0;
    if(prin.length()>1){
        std::cout<<"Intervalo "<<prin<<std::endl;
    } else{
        std::cout<<"Fora de intervalo"<<std::endl;
    }
    return 0;
}