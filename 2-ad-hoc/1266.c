#include<stdio.h>
//
int main(){
        for(;;){
                int length,temp,initCont=0,cont=0,tot=0,init=0;
                scanf("%i",&length);
                if(!length)
                        break;
                int array[length];
                for(int i=0;i<length;++i){
                        scanf("%i",&temp);
                        array[i]=temp;
                        temp?init=i:init;
                }
                for(int i=0,analysis;i<length+1;++i){
                        analysis=i<length-init?array[init+i]:array[i-length+init];
                        analysis?tot+=cont/2:tot;
                        !analysis?++cont:analysis?cont=0:cont;
                }
                tot+=cont/2;
                printf("%i\n",tot);
        }
        return 0;
}
