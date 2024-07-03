#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <stdio.h>
// 
int main(){
    float n=0, v[2][6]={{100,50,20,10,5,2},{1,0.5,0.25,0.1,0.05,0.01}};
    int r[2][6] ={{0,0,0,0,0,0},{0,0,0,0,0,0}};
    std::string prin="",t;
    std::cin>>n;
    for(int i=0;i<2;i++){
        int e=0;
        for(float j:v[i]){
            while(n>=j-0.009){
                r[i][e]++;
                n-=j;
            }
            ++e;
        }
    }
    for(int i=0;i<2;i++){
        int e=0;;
        (i==0)?prin="NOTA":prin="MOEDA";
        std::cout<<prin<<"S:"<<std::endl;
        std::transform(prin.begin(),prin.end(),prin.begin(),[](unsigned char trem){return std::tolower(trem);});
        for(int j:r[i]){
            std::cout<<j<<" "<<prin<<"(s) de R$ ";
            printf("%.2f\n",v[i][e]);
            e++;
        }
    }
    return 0;
}