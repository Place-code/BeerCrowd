#include <stdio.h>
// 
int main(){
    double x[3];
    for(int i=0;i<3;++i){
        scanf("%lf",&x[i]);
    }
    printf("NUMBER = %.0lf\n",x[0]);
    printf("SALARY = U$ %.2lf\n",x[1]*x[2]);
    return 0;
}