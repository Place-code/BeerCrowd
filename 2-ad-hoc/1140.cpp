#include <iostream>
#include <cstring>
// 
int main(){
    bool sim;
    char*split,res;
    int letra,dif;
    std::string *inp;
    while(true){
        sim=true;
        inp=new std::string;
        split=new char;
        std::getline(std::cin,*inp);
        if(*inp=="*"){
            break;
        }
        split=std::strtok(inp->data()," ");
        letra=int(split[0]);
        (letra<91)?dif=letra+32:(letra>96)?dif=letra-32:dif;
        for(int i=0;split!=NULL;++i){
            if(int(split[0])!=letra&&int(split[0])!=dif){
                split=NULL;
                sim=false;
                break;
            }
            split=std::strtok(NULL," ");
        }
        res='N';
        if(sim){
            res='Y';
            delete split;
            split=NULL;
        }
        std::cout<<res<<std::endl;
        delete inp;
        inp=NULL;
    }
    return 0;
}