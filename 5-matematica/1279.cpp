#include <iostream>
#include <cstring>
// 
int main(){
    int v_a,e,par,impar,p,aap;
    std::string big;
    bool passou,orid;
    while(true){
        std::getline(std::cin,big);
        if(big=="\0"){
            break;
        }
        v_a=0;
        par=0;
        impar=0;
        e=1;
        passou=true;
        orid=false;
        for(auto i:big){
            v_a+=std::atoi(&i);
            (e%2==0)?par+=std::atoi(&i):impar+=std::atoi(&i);
            ++e;
        }
        aap=std::atoi(&big[big.length()-4]);
        p=std::atoi(&big[big.length()-2]);
        if(p%4==0&&aap%100){
            std::cout<<"This is leap year.\n";
            if(v_a%3==0){
                if(big[big.length()-1]=='0'|big[big.length()-1]=='5'){
                    std::cout<<"This is huluculu festival year.\n";
                }
                passou=false;
            }
            if(impar-par==0|(par-impar)%11==0){
                std::cout<<"This is bulukulu festival year.\n";
            }
            orid=true;
        }else if(aap%400==0){
            std::cout<<"This is leap year.\n";
            if(v_a%3==0){
                if(big[big.length()-1]=='0'|big[big.length()-1]=='5'){
                    std::cout<<"This is huluculu festival year.\n";
                }
                passou=false;
            }
            if(impar-par==0|(par-impar)%11==0){
                std::cout<<"This is bulukulu festival year.\n";
            }
            orid=true;
        }
        if(v_a%3==0&&passou){
            if(big[big.length()-1]=='0'|big[big.length()-1]=='5'){
                std::cout<<"This is huluculu festival year.\n";
                orid=true;
            }
        }
        if(!orid){
            std::cout<<"This is an ordinary year.\n";
        }
        big.clear();
        std::cout<<"\n";
    }
    return 0;
}