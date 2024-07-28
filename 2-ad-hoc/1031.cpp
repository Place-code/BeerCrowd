#include <iostream>
#include <vector>
// 
int main(){
    int ordem,index,pa;
    std::vector<int>*posi,trem;
    while(true){
        std::cin>>ordem;
        // 
        std::cin.clear();
        std::cin.ignore(2147483647,'\n');
        // 
        if(ordem<1){
            break;
        }
        posi=new std::vector<int>;
        for(int i=0;i<ordem;++i){
            posi->push_back(i+1);
        }
        pa=0;
        while(true){
            trem=*posi;
            trem.erase(trem.begin());
            index=0;
            for(int i=ordem-1;i>0;--i){
                index=(index+pa)%i;
                trem.erase(trem.begin()+index);
                // for(auto bgl:trem){
                //     std::cout<<bgl<<" ";
                // }
                // std::cout<<std::endl;
            }
            // std::cout<<std::endl;
            if(trem[0]==13){
                break;
            }
            trem.clear();
            ++pa;
        }
        std::cout<<pa+1<<std::endl;
        delete posi;
        posi=NULL;
    }
    return 0;
}