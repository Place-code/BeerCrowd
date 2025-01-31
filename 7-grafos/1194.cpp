#include<iostream>
#include<cstdlib>
#include<vector>
#include<list>
//
int main(){
    std::string inps[2];
    int re,tam,index,index1,index2;
    std::cin>>re;
    for(int r=0;r<re;++r){
        std::cin>>tam>>inps[0]>>inps[1];
        std::list<char>fila;
        std::vector<int>alfa(52);
        for(int i=0;i<tam;++i){
            ((int)inps[1][i]<91)?alfa[(int)inps[1][i]-65]=i+1:alfa[(int)inps[1][i]-72]=i+1;
        }
        int*andados=(int*)calloc(52,sizeof(int)),ascii[2];
        fila.push_back(inps[0][0]);
        for(int i=1;i<tam;++i){
            for(;fila.size()>0;){
                ((int)fila.back()<91)?index=alfa[(int)fila.back()-65]-1:index=alfa[(int)fila.back()-72]-1;
                // std::cout<<index<<"\n";
                ascii[0]=ascii[1]=0;
                for(index1=index,index2=index;inps[1][index1]!=inps[0][i]&&inps[1][index2]!=inps[0][i];){
                    // std::cout<<index1<<" "<<index2<<"\n";
                    if(ascii[1]==1&&ascii[0]==1)
                        break;
                    (ascii[0]!=1&&index1>0)?--index1:index1;
                    (ascii[1]!=1&&index2<tam)?++index2:index2;
                    ((int)inps[1][index1]<91)?ascii[0]=andados[(int)inps[1][index1]-65]:ascii[0]=andados[(int)inps[1][index1]-72];
                    ((int)inps[1][index2]<91)?ascii[1]=andados[(int)inps[1][index2]-65]:ascii[1]=andados[(int)inps[1][index2]-72];
                    (index1<1)?ascii[0]=1:ascii[0];
                    (index2>tam-1)?ascii[1]=1:ascii[1];
                }
                // std::cout<<fila.back()<<"\n";
                if(inps[1][index1]==inps[0][i]||inps[1][index2]==inps[0][i]){
                    ((int)fila.back()<91)?andados[(int)fila.back()-65]=1:andados[(int)fila.back()-72]=1;
                    ((int)inps[0][i]<91)?andados[(int)inps[0][i]-65]=1:andados[(int)inps[0][i]-72]=1;
                    fila.push_back(inps[0][i]);
                    break;
                }
                std::cout<<fila.back()<<"";
                fila.pop_back();
            }
            // std::cout<<fila.back()<<"\n";
        }
        for(;fila.size()>0;){
            std::cout<<fila.back()<<"";
            fila.pop_back();
        }
        std::cout<<"\n";
    }
}