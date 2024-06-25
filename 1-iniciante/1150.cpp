#include <iostream>
using namespace std;
// 
int main(){
    int *x = (int*)malloc(34), z=0,e=1;
    cin>>*x;
    int xx=*x;
    while(z<=*x){
        cin>>z;
    }
    while(*x<=z){
        *x+=xx+1;
        ++xx;
        ++e;
    }
    cout<<e<<endl;
    return 0;
}