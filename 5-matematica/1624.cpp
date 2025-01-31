#include<iostream>
#include<vector>
#include<cstdlib>
//
int main(){
    int re,peso,*andar;
    for(;;){
        std::vector<std::vector<int>>lista(2);
        std::cin>>re;
        if(re==0)
            break;
        lista[0].resize(re);
        lista[1].resize(re);
        for(int i=0;i<re;++i){
            std::cin>>lista[0][i]>>lista[1][i];
        }
        std::cin>>peso;
        andar=(int*)calloc(peso+1,sizeof(int));
        for(int i=0;i<re;++i){
            for(int j=peso;j>lista[1][i]-1;--j){
                if(andar[j]<andar[j-lista[1][i]]+lista[0][i]){
                    andar[j]=andar[j-lista[1][i]]+lista[0][i];
                }
            }
        }
        std::cout<<andar[peso]<<"\n";
    }
    return 0;
}