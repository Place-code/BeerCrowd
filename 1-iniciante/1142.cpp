#include <iostream>
using namespace std;
// 
int main(){
    int *v = new int[3],n=0,vv=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            v[j]=vv;
            cout<<v[j]<<" ";
            if(j==2){
                cout<<"PUM"<<endl;
                ++vv;
            }
            ++vv;
        }
    }
}