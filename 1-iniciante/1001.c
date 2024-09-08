#include <stdio.h>
// 
int main(){
    int x[2];
    for(int i=0;i<2;++i){
        scanf("%d",&x[i]);
    }
    printf("X = %i\n",x[0]+x[1]);
    return 0;
}