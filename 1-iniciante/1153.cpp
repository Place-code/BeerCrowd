#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main(){
    int h;
    float *v=(float*)alloca(100);
    cin>>h;
    *v=h;
    --h;
    while(h>1){
        *v *= h;
        --h;
    }
    cout<<*v;
    cout<<"\n";
    return 0;
}