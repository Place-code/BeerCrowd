//Em construção
#include <iostream>
#include <cstring>
#include <vector>
// 
int main(){
    int d[2],l_t,quant;
    std::string inp;
    std::vector<int>*table;
    char*split;
    while(true){
        split=new char;
        std::getline(std::cin,inp);
        split=std::strtok(&inp[0]," ");
        for(int i=0;split!=NULL;++i){
            d[i]=std::atoi(split);
            split=std::strtok(NULL," ");
        }
        delete split;
        split=NULL;
        inp.clear();
        if(d[0]==0&&d[1]==0){
            break;
        }
        std::cin>>l_t;
        // 
        std::cin.clear();
        std::cin.ignore(2147483647,'\n');
        // 
        std::cin>>quant;
        // 
        std::cin.clear();
        std::cin.ignore(2147483647,'\n');
        // 
        split=new char;
        table=new std::vector<int>(quant);
        std::getline(std::cin,inp);
        split=std::strtok(&inp[0]," ");
        for(int i=0;split!=NULL;++i){
            table->operator[](i)=std::atoi(split);
        }
        delete table,split;
        table=NULL;
        split=NULL;

    }
    return 0;
}