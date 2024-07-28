#include <iostream>
#include <cstring>
#include<vector>
// 
int main(){
    bool calote;
    int v[2],end[3];
    std::vector<int>*banco;
    std::string inp;
    char*split,res;
    while(true){
        std::getline(std::cin,inp);
        split=new char;
        split=std::strtok(&inp[0]," ");
        for(int i=0;split!=NULL;++i){
            v[i]=std::atoi(split);
            split=std::strtok(NULL," ");
        }
        inp.clear();
        if(v[0]==0&&v[1]==0){
            break;
        }
        calote=true;
        delete split;
        split=NULL;
        split=new char;
        banco=new std::vector<int>(v[0]);
        std::getline(std::cin,inp);
        split=std::strtok(&inp[0]," ");
        for(int i=0;split!=NULL;++i){
            banco->operator[](i)=std::atoi(split);
            split=std::strtok(NULL," ");
        }
        for(int i=0;i<v[1];++i){
            delete split;
            split=NULL;
            inp.clear();
            std::getline(std::cin,inp);
            split=std::strtok(&inp[0]," ");
            for(int i=0;split!=NULL;++i){
                end[i]=std::atoi(split);
                split=std::strtok(NULL," ");
            }
            banco->operator[](end[0]-1)-=end[2];
            banco->operator[](end[1]-1)+=end[2];
        }
        for(int i:*banco){
            // std::cout<<i<<" ";
            if(i<0){
                calote=false;
                break;
            }
        }
        // std::cout<<std::endl;
        (calote)?res='S':res='N';
        std::cout<<res<<std::endl;
        delete banco;
    }
}