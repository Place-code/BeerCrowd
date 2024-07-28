#include <iostream>
// 
int main(){
    for(;;){
        int r;
        std::cin>>r;
        if(r==0){
            break;
        }
        for(int i=0;i<r;++i){
            if(i+1!=r){
                std::cout<<i+1<<" ";
            } else{
                std::cout<<i+1;
            }
        }
        std::cout<<std::endl;
    }
    return 0;
}