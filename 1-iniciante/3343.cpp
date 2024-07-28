#include <iostream>
#include <cstring>
#include <vector>
// 
int main(){
    std::vector<int> mu;
    std::string pmg;
    int tit[3],tam,indexs[3]={0,0,0},posi,sub=0,neg,divi,e;
    char *split=new char;
    std::string inp,v;
    std::getline(std::cin,v);
    split=std::strtok(&v[0]," ");
    for(int i=0;split!=NULL;++i){
        (i>0)?divi=std::atof(split):tam=std::atoi(split);
        split=std::strtok(NULL," ");
    }
    sub=divi;
    mu.push_back(divi);
    v.clear();
    std::cin>>pmg;
    // 
    std::cin.clear();
    std::cin.ignore(2147483647,'\n');
    // 
    std::getline(std::cin,v);
    split=std::strtok(&v[0]," ");
    for(int i=0;split!=NULL;++i){
        (i<3)?tit[i]=std::atof(split):tit[i];
        split=std::strtok(NULL," ");
    }
    for(char i:pmg){
        (i=='P')?posi=0:(i=='M')?posi=1:(i=='G')?posi=2:posi;
        if(tit[posi]<=mu[indexs[posi]]){
            mu[indexs[posi]]-=tit[posi];
        } else{
            ++indexs[posi];
            if(indexs[posi]>mu.size()-1){
                mu.push_back(divi);
            }
            if(mu[indexs[posi]]<tit[posi]){
                while(mu[indexs[posi]]<tit[posi]){
                    ++indexs[posi];
                    if(indexs[posi]>mu.size()-1){
                        mu.push_back(divi);
                    }
                }
            }
            mu[indexs[posi]]-=tit[posi];
            if(mu[indexs[posi]]<0){
                neg=mu[indexs[posi]];
                while(mu[indexs[posi]]<0){
                    ++indexs[posi];
                    if(indexs[posi]>mu.size()-1){
                        mu.push_back(divi);
                    }
                    mu[indexs[posi]]+=neg;
                    neg+=mu[indexs[posi]];
                }
            }
        }
    }
    std::cout<<mu.size()<<std::endl;
}