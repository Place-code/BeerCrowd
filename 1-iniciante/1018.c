#include <stdio.h>
#include <stdlib.h>
// 
int main(){
    int ce,not[]={100,50,20,10,5,2,1},*quant=(int*)calloc(7,sizeof(int));
    scanf("%i",&ce);
    printf("%i\n",ce);
    for(int i=0;ce>0;++i){
        quant[i]+=(int)ce/not[i];
        ce-=not[i]*((int)ce/not[i]);
    }
    for(int i=0;i<7;++i){
        printf("%i nota(s) de R$ %i,00\n",quant[i],not[i]);
    }
    return 0;
}