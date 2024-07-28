#include <iostream>
#include <vector>
#include <cstring>
// 
int main(){
    std::string inp;
    int v[2],result;
    std::vector<int>*trens,*cit;
    char*split;
    bool pode;
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
        inp.clear();
        trens=new std::vector<int>(v[1]);
        cit=new std::vector<int>;
        // 
        std::getline(std::cin,inp);
        split=std::strtok(&inp[0]," ");
        for(int i=0;split!=NULL;++i){
            trens->operator[](i)=std::atoi(split);
            split=std::strtok(NULL," ");
        }
        delete split;
        split=NULL;
        for(int i:*trens){
            for(int j:*trens){
                result=0;
                result=i-j;
                (result<0)?result*=-1:result;
                pode=true;
                for(int k:*cit){
                    if(k==result){
                        pode=false;
                        break;
                    }
                }
                if(pode){
                    cit->push_back(result);
                }
            }
        }
        if(cit->size()<=v[0]){
            std::cout<<"N"<<std::endl;
        } else{
            std::cout<<"Y"<<std::endl;
        }
        delete trens,cit;
        trens=cit=NULL;
    }
    return 0;
}