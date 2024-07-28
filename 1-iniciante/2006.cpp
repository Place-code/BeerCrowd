#include <iostream>
#include <cstring>
// 
int main(){
    char *split;
    int c=0;
    std::string bgl,trem;
    std::cin>>trem;
    // 
    std::cin.clear();
    std::cin.ignore(2147483647,'\n');
    // 
    std::getline(std::cin,bgl);
    split=std::strtok(&bgl[0]," ");
    while(split!=NULL){
        (split==trem)?++c:c;
        split=std::strtok(NULL," ");
    }
    std::cout<<c<<std::endl;
    return 0;
}