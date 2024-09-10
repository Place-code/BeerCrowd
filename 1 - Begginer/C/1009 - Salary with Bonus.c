#include <stdio.h>
 
int main() {
 
    char name[20];
    double salary, v_sold, t_salary;
    
    scanf("%s %lf %lf", name, &salary, &v_sold);
    
    t_salary = salary + v_sold * 0.15;
    
    printf("TOTAL = R$ %.2lf\n", t_salary);
 
    return 0;
}