#include<iostream>
#include<vector>
#include<list>
//
int main(){
    int pp[2];
    for(;;){
        std::cin>>pp[0]>>pp[1];
        if(pp[0]==0&&pp[1]==0){
            break;
        }
        std::vector<std::vector<int>>corridas(pp[0]);
        std::list<int>titulos;
        int v,outro,tam,ant;
        for(int i=0;i<pp[0];++i){
            corridas[i].resize(pp[1]);
            for(int j=0;j<pp[1];++j){
                std::cin>>v;
                corridas[i][v-1]=j;
            }
        }
        std::cin>>outro;
        for(int i=0;i<outro;++i){
            std::vector<int>pontos(pp[1]);
            std::cin>>tam;
            ant=0;
            for(int j=0;j<tam;++j){
                std::cin>>v;
                for(int k=0;k<pp[0];++k){
                    pontos[corridas[k][j]]+=v;
                    if(ant<pontos[corridas[k][j]]){
                        titulos.clear();
                        ant=pontos[corridas[k][j]];
                        titulos.push_back(corridas[k][j]);
                    } else if(ant==pontos[corridas[k][j]]){
                        titulos.push_back(corridas[k][j]);
                    }
                }
            }
            for(int menor,index,n_index;titulos.size()>0;){
                std::list<int>::iterator aux=titulos.begin();
                n_index=0;
                menor=101;
                for(std::list<int>::iterator isto=titulos.begin();isto!=titulos.end();++isto){
                    if(*isto<menor){
                        menor=*isto;
                        index=n_index;
                    }
                    ++n_index;
                }
                if(titulos.size()>1){
                    std::cout<<menor+1<<" ";
                } else{
                    std::cout<<menor+1<<"\n";
                }
                std::advance(aux,index);
                titulos.erase(aux);
            }
        }
    }
}