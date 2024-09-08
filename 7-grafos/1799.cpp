#include<iostream>
#include<list>
#include<vector>
#include<map>
#include<cstdlib>
//
int main(){
    std::vector<std::vector<int>>andados;
    std::map<std::string,int>trocas;
    std::string ds[2];
    int v[2],tam=0;
    bool capa;
    std::cin>>v[0]>>v[1];
    andados.resize(v[0]);
    for(int i=0;i<v[1];++i){
        std::cin>>ds[0]>>ds[1];
        for(int j=0;j<2;++j){
            if(trocas.find(ds[j])==trocas.end()){
                trocas[ds[j]]=tam;
                ++tam;
            }
        }
        andados[trocas[ds[0]]].push_back(trocas[ds[1]]);
        andados[trocas[ds[1]]].push_back(trocas[ds[0]]);
    }
    auto bfs=[trocas,andados,tam](int init,int end)->int{
        std::list<int>fila{init},aux;
        int*arres=(int*)calloc(tam,sizeof(int));
        bool para=true;
        int cont=0;
        for(;para;){
            for(;fila.size()>0;){
                for(int vs:andados[fila.back()]){
                    if(vs==end){
                        para=false;
                        break;
                    } else if(arres[vs]==0){
                        aux.push_back(vs);
                        arres[vs]=1;
                    }
                }
                if(!para){
                    break;
                }
                fila.pop_back();
            }
            fila.merge(aux);
            aux.clear();
            ++cont;
        }
        return cont;
    };
    std::cout<<bfs(trocas["Entrada"],trocas["*"])+bfs(trocas["*"],trocas["Saida"])<<"\n";
    return 0;
}