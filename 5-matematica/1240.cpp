#include <iostream>
#include <cstring>
// 
int main()
{
    int r;
    std::cin>>r;
    // 
    std::cin.clear();
    std::cin.ignore(2147483647,'\n');
    // 
    for(int i=0;i<r;i++){
        std::string n, *nn= new std::string[2];
        std::getline(std::cin,n);
        int tam=0;
        bool ver=true;
        char *split=std::strtok(&n[0]," ");
        for(int j=0;split!=NULL;j++){
            nn[j]=split;
            split=std::strtok(NULL," ");
        }
        (nn[0].length()>=nn[1].length())?tam=nn[1].length():ver=false;
        for(int j=0;j<2;j++){
            for(int k=0;k<int(nn[j].length()/2);k++){
                char *aux= new char(nn[j][k]);
                nn[j][k]=nn[j][nn[j].length()-k-1];
                nn[j][nn[j].length()-k-1]=*aux;
                delete[] aux;
                aux=NULL;
            }
        }
        // std::cout<<nn[0]<<" "<<nn[1]<<" "<<tam<<std::endl;
        for(int j=0;j<tam;j++){
            if(nn[0][j]!=nn[1][j]){
                ver=false;
                break;
            }
        }
        if(ver){
            std::cout<<"encaixa"<<std::endl;
        } else{
            std::cout<<"nao encaixa"<<std::endl;
        }
    }
    return 0;
}