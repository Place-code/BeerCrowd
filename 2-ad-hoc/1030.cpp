#include <iostream>
#include <vector>
#include <cstring>
// 
int jose(int p,int pss){
    if(p==1)
        return 1;
    else
        return(jose(p-1,pss)+pss-1)%p+1;
}
int main(){
    int r,paso=0,pe,pax;;
    std::cin>>r;
    // 
    std::cin.clear();
    std::cin.ignore(2147483647,'\n');
    // 
    for(int i=0;i<r;i++){
        std::string ns;
        std::getline(std::cin,ns);
        char*split=std::strtok(&ns[0]," ");
        for(int j=0;split!=NULL;j++){
            (j==0)?pe=std::stoi(split):pax=std::stoi(split);
            split=std::strtok(NULL," ");
        }
        std::cout<<"Case "<<std::to_string(i+1)+": "<<jose(pe,pax)<<std::endl;
        delete split;
        split=NULL;
    }
    return 0;
}