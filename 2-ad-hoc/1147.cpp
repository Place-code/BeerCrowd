#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<cstdio>
//
int main(){
    std::string inp;
    int*posi,**tabu,*movi;
    for(int cont=1;;++cont){
        for(int i=0;i<9;++i){
            std::cin>>inp;
            if(inp=="0"){
                break;
            }
            //
            std::cin.clear();
            std::cin.ignore(2147483647,'\n');
            //
            if(i==0){
                posi=new int[2]{inp[0]-'0'-1,(int)inp[1]-97};
                tabu=new int*[8];
                for(int j=0;j<8;++j){
                    tabu[j]=new int[8]{0,0,0,0,0,0,0,0};
                }
            } else if(inp[0]-'0'>1){
                ((int)inp[1]-97>0)?tabu[(inp[0]-'0')-2][(int)inp[1]-97-1]=1:tabu[0][0];
                ((int)inp[1]-97<7)?tabu[(inp[0]-'0')-2][(int)inp[1]-97+1]=1:tabu[0][0];
            }
        }
        if(inp=="0"){
            break;
        }
        movi=new int(0);
        for(int i=0;i<2;++i){
            if(posi[0]+2-i<=7){
                (tabu[posi[0]+2-i][posi[1]+i+1]==0&&posi[1]+i+1<=7)?++*movi:*movi;
                (tabu[posi[0]+2-i][posi[1]-i-1]==0&&posi[1]-i-1>=0)?++*movi:*movi;
            }
            if(posi[0]-2+i>=0){
                (tabu[posi[0]-2+i][posi[1]+i+1]==0&&posi[1]+i+1<=7)?++*movi:*movi;
                (tabu[posi[0]-2+i][posi[1]-i-1]==0&&posi[1]-i-1>=0)?++*movi:*movi;
            }
        }
        std::printf("Caso de Teste #%i: %i movimento(s).\n",cont,*movi);
        delete movi;
        movi=NULL;
        delete tabu;
        tabu=NULL;
        delete posi;
        posi=NULL;
    }
    return 0;
}