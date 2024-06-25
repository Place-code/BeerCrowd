#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

int main(){
    double r,v;
    cin>>r;
    v=(4/3.0)*3.14159*pow(r,3);
    cout<<"VOLUME  = ";
    printf("%6.3f%n",v);
    cout<<"\n";
    return 0;
}