#include <iostream>
#include <vector>
// 
int main(){
    int r;
    std::cin>>r;
    std::vector<int> s={1};
    for(int i=0;i<r;++i){
        unsigned x;
        std::cin>>x;
        if(x!=s.back()){
            s.push_back(x);
        }
    }
    std::cout<<s.size()<<std::endl;
    return 0;
}