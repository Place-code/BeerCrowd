#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
//
int main(){
    std::map<std::string,std::vector<std::string>>*camino;
    std::vector<std::string>*alfa,*fila,conexos;
    std::string dados[2];
    int r,*v,index;
    const int*tam;
    bool nao;
    std::cin>>r;
    // 
    std::cin.clear();
    std::cin.ignore(2147483647,'\n');
    // 
    // getchar();
    for(int i=0;i<r;++i){
        v=new int[3]{0,0,0};
        for(int j=0;j<2;++j){
            std::cin>>v[j];
            if(j==0){
                alfa=new std::vector<std::string>(v[0]);
                camino=new std::map<std::string,std::vector<std::string>>;
                for(int k=0;k<v[0];++k){
                    alfa->operator[](k)=(char)k+97;
                    camino->insert(camino->end(),std::pair<std::string,std::vector<std::string>>(alfa->operator[](k),{}));
                }
            }
        }
        for(int j=0;j<v[1];++j){
            for(int k=0;k<2;++k){
                std::cin>>dados[k];
            }
            camino->operator[](dados[0]).push_back(dados[1]);
            camino->operator[](dados[1]).push_back(dados[0]);
        }
        std::printf("Case #%i:\n",i+1);
        fila=new std::vector<std::string>;
        for(;alfa->size()>0;){
            fila->push_back(alfa->operator[](0));
            alfa->erase(alfa->begin());
            for(;fila->size()>0;){
                tam=new const int(fila->size());
                for(int j=0;j<*tam;++j){
                    nao=true;
                    for(const std::string analise:camino->operator[](fila->operator[](j))){
                        nao=true;
                        for(index=0;index<alfa->size();++index){
                            if(analise==alfa->operator[](index)){
                                nao=false;
                                break;
                            }
                        }
                        if(!nao){
                            fila->push_back(alfa->operator[](index));
                            alfa->erase(alfa->begin()+index);
                        }
                    }
                }
                delete tam;
                conexos.insert(conexos.begin(),fila->operator[](0));
                fila->erase(fila->begin());
            }
            for(int i=conexos.size()-1;i>-1;--i){
                for(int j=i;j>-1;--j){
                    if(conexos[j]>conexos[i]){
                        dados[0]=conexos[i];
                        conexos[i]=conexos[j];
                        conexos[j]=dados[0];
                    }
                }
            }
            for(const std::string bgl:conexos){
                std::cout<<bgl<<",";
            }
            std::cout<<"\n";
            conexos.clear();
            ++v[2];
        }
        std::printf("%i connected components\n\n",v[2]);
        delete camino;
        camino=NULL;
        delete fila;
        fila=NULL;
        delete alfa;
        alfa=NULL;
        delete v;
        v=NULL;
    }
    return 0;
}