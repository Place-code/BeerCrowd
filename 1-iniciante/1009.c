#include <stdio.h>
// 
int main(){
    char x[10];
    double didin[2];
    scanf("%s",&x);
    for(int i=0;i<2;++i){
        scanf("%lf",&didin[i]);
    }
    printf("TOTAL = R$ %.2lf\n",didin[0]+(didin[1]*15)/100);
    return 0;
}