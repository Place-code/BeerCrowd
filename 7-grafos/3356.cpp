#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<cstdlib>
//
int main(){
    std::vector<std::vector<int>>l_adj;
    std::map<std::string,int>troca;
    std::string inp[3];
    int v[3],tam=0;
    std::cin>>v[0]>>v[1]>>v[2];
    l_adj.resize(v[0]);
    for(int i=0;i<v[1];++i){
        for(int j=0;j<3;++j){
            std::cin>>inp[j];
            if(troca.find(inp[j])==troca.end()){
                troca[inp[j]]=tam;
                ++tam;
            }
        }
        l_adj[troca[inp[2]]].insert(l_adj[troca[inp[2]]].end(),{troca[inp[0]],troca[inp[1]]});
    }
    bool sim=false;
    int*andados;
    for(int i=0;i<v[2];++i){
        sim=false;
        andados=(int*)calloc(v[0],sizeof(int));
        std::cin>>inp[0]>>inp[1];
        //
        std::cin.clear();
        std::cin.ignore(2147483647,'\n');
        //
        std::list<int>fila{troca[inp[0]],troca[inp[1]]},aux;
        andados[troca[inp[0]]]=andados[troca[inp[1]]]=1;
        for(;;){
            for(int bgl:l_adj[fila.back()]){
                if(andados[bgl]==1){
                    sim=true;
                    aux.clear();
                    fila.clear();
                    break;
                }
                andados[bgl]=1;
                aux.push_back(bgl);
            }
            if(fila.size()==0&&aux.size()==0)
                break;
            fila.pop_back();
            if(fila.size()==0){
                fila.merge(aux);
                aux.clear();
            }
        }
        if(sim)
            std::cout<<"verdadeiro\n";
        else
            std::cout<<"falso\n";
        delete andados;
        andados=NULL;
    }
}