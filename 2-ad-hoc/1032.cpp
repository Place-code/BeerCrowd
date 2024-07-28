#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
// 
int main(){
    char*split;
    std::string inp;
    bool nao,pri;
    int pa,index,e;
    std::vector<int> *mapa,*entry,*primos;
    while(true){
        split=new char;
        entry=new std::vector<int>;
        std::getline(std::cin,inp);
        split=std::strtok(&inp[0]," ");
        for(int i=0;split!=NULL;++i){
            entry->push_back(std::atoi(split));
            split=std::strtok(NULL," ");
        }
        if(entry->operator[](0)==0){
            break;
        }
        for(int n:*entry){
            index=0;
            e=0;
            mapa=new std::vector<int>(n);
            primos=new std::vector<int>{2};
            for(int i=0;i<n;++i){
                mapa->operator[](i)=i+1;
            }
            for(int i=mapa->size();i>0;--i){
                pa=primos->operator[](e)-1;
                index=(index+pa)%i;
                mapa->erase(mapa->begin()+index);
                nao=true;
                for(int j=primos->operator[](primos->size()-1)+1;nao;++j){
                    pri=true;
                    for(int k:*primos){
                        if(k>pow(j,0.5)|j%k==0){
                            (j%k==0)?pri=false:pri;
                            break;
                        }
                    }
                    if(pri){
                        primos->push_back(j);
                        nao=false;
                    }
                }
                ++e;
            }
            std::cout<<mapa->operator[](0)<<std::endl;
            delete mapa,primos;
            mapa=primos=NULL;
        }
        delete entry,split;
        entry=NULL;
        split=NULL;
    }
    return 0;
}