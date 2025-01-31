#include<iostream>
#include<cstring>
#include<vector>
#include<list>
//
int main(){
    std::string inps[2],bgl;
    char*split;
    for(;;){
        std::getline(std::cin,bgl);
        if(bgl.length()<1)
            break;
        split=std::strtok(&bgl[0]," ");
        for(int i=0;split!=NULL;++i){
            inps[i]=split;
            split=std::strtok(NULL," ");
        }
        if(inps[0].length()<1)
            break;
        std::vector<int>alfa(26);
        std::list<char>fila;
        int index=inps[0].length()/2,ascii[2];
        const int tam=inps[0].length();
        for(int i=0;i<tam;++i){
            for(int index1,index2;;){
                (i>0)?index=alfa[(int)fila.back()-65]:index;
                // std::cout<<index<<"\n";
                ascii[0]=ascii[1]=0;
                for(index1=index,index2=index;inps[1][index1]!=inps[0][i]&&inps[1][index2]!=inps[0][i];){
                    if(ascii[0]!=0&&ascii[1]!=0)
                        break;
                    (index1>0)?--index1:index1;
                    (index2<tam-1)?++index2:index2;
                    ascii[0]=alfa[(int)inps[1][index1]-65];
                    ascii[1]=alfa[(int)inps[1][index2]-65];
                    (index1<1)?ascii[0]=1:ascii[0];
                    (index2>tam-1)?ascii[1]=1:ascii[1];
                    // std::cout<<index1<<" "<<index2<<" "<<ascii[0]<<" "<<ascii[1]<<"\n";
                }
                if(inps[1][index1]==inps[0][i]|inps[1][index2]==inps[0][i]){
                    (inps[1][index1]==inps[0][i])?alfa[(int)inps[1][index1]-65]=index1:alfa[(int)inps[1][index2]-65]=index2;
                    fila.push_back(inps[0][i]);
                    break;
                }
                std::cout<<fila.back()<<"";
                fila.pop_back();
            }
        }
        for(;fila.size()>0;){
            std::cout<<fila.back()<<"";
            fila.pop_back();
        }
        std::cout<<"\n";
    }
}