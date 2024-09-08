//5% de wrong answer
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//
void main(){
    char*inp,*inp2,*split;
    int v[2],op[2],**cartas,*es,tot,*ant;
    for(;;){
        inp2=(char*)malloc(20*sizeof(char));
        fgets(inp2,20,stdin);
        for(int i=0;split=strtok_r(inp2," ",&inp2);++i){
            v[i]=atoi(split);
        }
        if(v[0]==0&&v[1]==0)
            break;
        cartas=(int**)malloc(2*sizeof(int*));
        ant=(int*)malloc(1*sizeof(int));
        es=(int*)calloc(2,sizeof(int));
        for(int i=0;i<2;++i){
            inp=(char*)malloc(1000000*sizeof(char));
            fgets(inp,1000000,stdin);
            // printf("Ok\n");
            cartas[i]=(int*)calloc(v[i],sizeof(int));
            for(int j=0;split=strtok_r(inp," ",&inp);++j){
                if(*ant!=atoi(split)){
                    cartas[i][es[i]]=atoi(split);
                    ++es[i];
                }
                *ant=atoi(split);
            }
        }
        if(es[0]<=es[1]){
            op[0]=0;
            op[1]=1;
        } else{
            op[1]=0;
            op[0]=1;
            es[1]+=es[0];
            es[0]=es[1]-es[0];
            es[1]-=es[0];
        }
        // printf("%i %i\n",es[0],es[1]);
        // for(int i=0;i<2;++i){
        //     for(int j=0;j<es[op[i]];++j){
        //         printf("%i ",cartas[i][j]);
        //     }
        //     printf("\n");
        // }
        --es[0];
        --es[1];
        tot=0;
        for(;es[0]>=0;){
            // printf("%i %i %i\n",es[0],es[1],tot);
            if(cartas[op[0]][es[0]]<cartas[op[1]][es[1]]){
                --es[1];
                for(es[1];cartas[op[0]][es[0]]<cartas[op[1]][es[1]]&&es[1]>=0;--es[1]){}
                if(cartas[op[0]][es[0]]!=cartas[op[1]][es[1]]){
                    ++tot;
                    --es[0];
                } else{
                    --es[0];
                    --es[1];
                }
            } else if(cartas[op[0]][es[0]]>cartas[op[1]][es[1]]){
                for(es[0];cartas[op[0]][es[0]]>cartas[op[1]][es[1]]&&es[0]>=0;--es[0]){
                    ++tot;
                }
                if(cartas[op[0]][es[0]]>cartas[op[1]][es[1]]){
                    ++tot;
                } else if(cartas[op[0]][es[0]]==cartas[op[1]][es[1]]){
                    --es[0];
                    --es[1];
                }
            } else{
                --es[0];
                --es[1];
            }
        }
        printf("%i\n",tot+es[0]+1);
        free(cartas);
        free(es);
    }
}