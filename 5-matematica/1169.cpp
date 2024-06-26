#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstring>
using namespace std;
// 
int main(){
    int r;
    cin>>r;
    for(int j=0;j<r;j++){
        int elevado=0;
        double *v= new double;
        string x;
        cin>>elevado;
        *v=(pow(2,elevado)/1000)/12;
        x=to_string(*v);
        for(int i=0;i<sizeof(x);i++){
            if(x[i]=='.'){
                break;
            }
            cout<<x[i];
        }
        cout<<" kg"<<endl;
        delete v;
        x="";
        elevado=0;
    }
    return 0;
}