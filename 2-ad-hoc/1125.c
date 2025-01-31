#include<stdio.h>
#include<stdlib.h>
//
int main(){
    int vs[3],**run,*pontos,*final;
    for(;;){
        scanf("%i %i",&vs[0],&vs[1]);
        if(vs[0]==0&&vs[1]==0){
            break;
        }
        run=(int**)malloc(vs[0]*sizeof(int*));
        for(int i=0;i<vs[0];++i){
            run[i]=(int*)malloc(vs[1]*sizeof(int));
            for(int j=0;j<vs[1];++j){
                scanf("%i",&vs[3]);
                run[i][vs[3]-1]=j;
            }
        }
        scanf("%i",&vs[2]);
        for(int i=0,ant;i<vs[2];++i){
            int ant=0,tam,pt,stack=0;
            final=(int*)calloc(vs[1],sizeof(int));
            pontos=(int*)calloc(vs[1],sizeof(int));
            scanf("%i",&tam);
            for(int j=0;j<tam;++j){
                scanf("%i",&pt);
                for(int k=0;k<vs[0];++k){
                    pontos[run[k][j]]+=pt;
                    if(ant<pontos[run[k][j]]){
                        for(int l=0;l<vs[1];++l){
                            final[l]=0;
                        }
                        ant=pontos[run[k][j]];
                        final[run[k][j]]=1;
                    } else if(ant==pontos[run[k][j]]){
                        final[run[k][j]]=1;
                    }
                }
            }
            for(int j=0;j<vs[1];++j){
                if(final[j]==1&&stack!=0)
                    printf("%i ",stack);
                final[j]==1?stack=j+1:stack;
            }
            printf("%i\n",stack);
            free(pontos);
            free(final);
        }
        free(run);
    }
    return 0;
}