#include<cstdio>
#include<map>
//
int main(){
    std::map<int,int>chave;
    int r,n;
    std::scanf("%i",&r);
    for(int i=0;i<r;++i){
        std::scanf("%i",&n);
        (chave.find(n)==chave.end())?chave[n]=1:chave[n]+=1;
    }
    for(auto bgl:chave){
        std::printf("%i aparece %i vez(es)\n",bgl.first,bgl.second);
    }
}