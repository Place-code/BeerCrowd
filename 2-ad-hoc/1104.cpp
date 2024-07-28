#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
// 
int main(){
    int e,e1,e2,index,index_con,posi,esco;
    bool passa;
    std::string inp;
    std::vector<std::vector<int>> cartas;
    char *split;
    while(true){
        posi=0;
        index=0;
        index_con=1;
        e=0;
        std::cin>>e1>>e2;
        for(int i=0;i<2;++i){
            split=new char;
            std::getline(std::cin,inp);
            split=std::strtok(&inp[0]," ");
            cartas.push_back({});
            while(split!=NULL){
                cartas[cartas.size()-1].push_back(std::stoi(split));
                split=std::strtok(NULL," ");
            }
            inp.clear();
            delete split;
            split=NULL;
        }
        if(e1<e2){
            e1=e2;
            index=1;
            index_con=0;
        }
        for(int i=0;i<e1;++i){
            passa=true;
            for(auto j:cartas[index]){
                if(j==cartas[index_con][e1]){
                    passa=false;
                }
            }
            if(passa){
                passa=false;
                for(auto j:cartas[index_con]){
                    if(std::find(cartas[index].begin(),cartas[index].end(),j)==cartas[index].end()){
                        esco=j;
                        passa=true;
                    }
                }
                if(passa){
                    cartas[index].push_back(esco);
                    cartas[index_con].push_back
                }   
            }
            ++e;
        }
    }
}