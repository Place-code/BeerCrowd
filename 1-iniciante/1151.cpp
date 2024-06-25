#include <iostream>
#include <stdio.h>
using namespace std;
//
int main(){
    int fib;
    double v[2] = {0,1};
    cin>>fib;
    for(int i=0;i<fib;i++){
        printf("%.0f",v[0]);
        if(i!=fib-1){
          cout<<" ";   
        }
        v[1]=v[1]+v[0];
        v[0]=v[1]-v[0];
    } 
    cout<<"\n";
    return 0;
}