#include <iostream>
#include <cstring>
#include <map>
// 
int main()
{
    std::string v;
    std::getline(std::cin,v);
    char*split=std::strtok(&v[0]," ");
    int mana, r;
    for(int i=0; split!=NULL;i++){
        (i==0)?r=std::stoi(split):mana=std::stoi(split);
        split=std::strtok(NULL," ");
    }
    auto meu_precioso=[=]()->int{
        std::map<char,int> anao;
        unsigned x=0;
        std:: string runas;
        int result=0;
        for(int i=0;i<r;i++){
            std::string *troco=new std::string[1];
            char letra[1], num[5];
            std::getline(std::cin,*troco);
            // 
            // std::cin.clear();
            // std::cin.ignore(2147483647,'\n');
            // 
            letra[0]=troco[0][0];
            for(int i=2;i<=troco->length();i++){
                num[i-2]=troco[0][i];
            }
            anao[letra[0]]=atoi(num);
            delete[] troco;
            troco=NULL;
        }        
        std::cin>>x;
        
        std::cin.clear();
        std::cin.ignore(2147483647,'\n');
        
        std::getline(std::cin,runas);
        char *spli=std::strtok(&runas[0]," ");
        while (spli != NULL){
            result+=anao[*spli];
            spli=strtok(NULL," ");
        }
        std::cout<<result<<std::endl;
        return result;
    };
    auto bob=meu_precioso();
    if(bob>=mana){
        std::cout<<"You shall pass!"<<std::endl;
    } else{
        std::cout<<"My precioooous"<<std::endl;
    }
    return 0;
}