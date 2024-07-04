#include <iostream>
#include <map>
#include <vector>
#include <cstring>
// 
int main()
{
    int r;
    std::cin>>r;
    for(int i=0;i<r;i++){
        int init=0, ares, vert;
        std::map<int, std::vector<std::vector<int>>> *camino;
        std::string va;
        std::cin>>init;
        // 
        std::cin.clear();
        std::cin.ignore(2147483647,'\n');
        // 
        std::getline(std::cin,va);
        char*split=std::strtok(&va[0]," ");
        for(int j=0;split!=NULL;j++){
            (j==0)?vert=std::stoi(split):ares=std::stoi(split);
            split=std::strtok(NULL," ");
        }
        for(int j=0;j<vert;j++){
            std::cout<<"DEU RUIM"<<std::endl;
            (*camino)[j]={};
        }
        for(int j=0;j<ares;j++){
            std::string trem;
            int p1,p2;
            std::getline(std::cin,trem);
            char*dividir=std::strtok(&trem[0]," ");
            for(int k=0;dividir!=NULL;k++){
                (k==0)?p1=std::stoi(dividir):p2=std::stoi(dividir);
                dividir=std::strtok(NULL," ");
            }
            camino->operator[](p1).push_back({p2,0,0});
            camino->operator[](p2).push_back({p1,0,0});
        }
        for(auto j:*camino){
            std::cout<<j.first<<" ";
            for(auto k:j.second){
                for(auto l:k){
                    std::cout<<l<<" ";
                }
            }
            std::cout<<std::endl;
        }
    }
}