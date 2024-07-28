#include <iostream>
#include <cstring>
// 
int main(){
    int v[2],ant_n,p;
    char*split;
    std::string mapa,inp;
    while(true){
        std::getline(std::cin,inp);
        split=new char;
        split=std::strtok(&inp[0]," ");
        for(int i=0;split!=NULL;++i){
            v[i]=std::atoi(split);
            split=std::strtok(NULL," ");
        }
        if(v[0]==0&&v[1]==0){
            break;
        }
        p=0;
        ant_n=0;
        std::getline(std::cin,mapa);
        int indexs[v[1]];
        split=std::strtok(&mapa[0]," ");
        for(int i=0;split!=NULL;++i){
            indexs[i]=std::atoi(split);
            split=std::strtok(NULL," ");
        }
        p=v[0]-indexs[0];
        for(int i:indexs){
            (ant_n>i)?p+=(ant_n-i):p;
            ant_n=i;
        }
        std::cout<<p<<std::endl;
        delete split;
        split=NULL;
    }
    return 0;
}