#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
#include<cstdlib>
#include<algorithm>
//
int main(){
    std::vector<std::vector<int>>camino;
    int r,v[4],*andados;
    bool trem,vai;
    std::cin>>r;
    auto dfs=[&camino,&andados](int init)->bool{
        int espacamento=1,menor,index,n_index;
        bool sim=false;
        std::list<int>fila{init};
        andados[init]=1;
        for(;;){
            index=n_index=0;
            menor=21;
            for(;camino[fila.back()].size()<1&&fila.size()>1;){
                --espacamento;
                fila.pop_back();
            }
            if(camino[fila.back()].size()<1)
                break;
            sim=true;
            for(int bgl:camino[fila.back()]){
                if(bgl<menor){
                    menor=bgl;
                    index=n_index;
                }
                ++n_index;
            }
            if(camino[fila.back()].size()>0){
                camino[fila.back()].erase(camino[fila.back()].begin()+index);
            }
            for(int i=0;i<espacamento*2;++i){
                std::printf(" ");
            }
            if(andados[menor]==0)
                std::printf("%i-%i pathR(G,%i)\n",fila.back(),menor,menor);
            else{
                std::printf("%i-%i\n",fila.back(),menor);
            }
            fila.push_back(menor);
            andados[menor]=1;
            ++espacamento;
        }
        return sim;
    };
    for(int re=0;re<r;++re){
        std::cin>>v[0]>>v[1];
        //
        std::cin.clear();
        std::cin.ignore(2147483647,'\n');
        //
        camino.resize(v[0]);
        for(int i=0;i<v[1];++i){
            std::cin>>v[2]>>v[3];
            vai=true;
            for(int treco:camino[v[2]]){
                if(treco==v[3]){
                    vai=false;
                    break;
                }
            }
            if(vai)
                camino[v[2]].push_back(v[3]);
            //
            std::cin.clear();
            std::cin.ignore(2147483647,'\n');
            //
        }
        andados=(int*)calloc(v[0],sizeof(int));
        std::printf("Caso %i:\n",re+1);
        for(int i=0;i<v[0];++i){
            if(andados[i]==0){
                trem=dfs(i);
                if(i!=v[2]-1&&trem)
                    std::printf("\n");
            }
        }
        camino.clear();
        delete andados;
        andados=NULL;
    }
    return 0;
}