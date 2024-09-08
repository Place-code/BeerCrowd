#include <stdio.h>
// 
int main(){
    double x[2];
    for(int i=0;i<2;++i){
        scanf("%lf",&x[i]);
    }
    printf("MEDIA = %.5lf\n",(x[0]*3.5+x[1]*7.5)/11.0);
    return 0;
}