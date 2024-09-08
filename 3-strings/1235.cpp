#include<iostream>
#include<cstdio>
#include<cstring>
//
int main(){
    std::string inp;
    char*prin;
    int r;
    std::cin>>r;
    //
    std::cin.clear();
    std::cin.ignore(2147483647,'\n');
    //
    for(int i=0;r>i;++i){
        std::getline(std::cin,inp);
        const int*tam=new int(inp.length()-1);
        for(int i=0;i<*tam+1;++i){
            if(i<*tam/2+1){
                prin=&inp[*tam/2-i];
            } else{
                prin=&inp[*tam-(i-*tam/2-1)];
            }
            std::cout<<*prin;
        }
        std::cout<<"\n";
        delete tam;
        tam=NULL;
    }
    return 0;
}