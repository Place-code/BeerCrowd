#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string r;
    cin>>r;
    for(int i=0;i<stoi(r);i++){
        char n[10];
        cin>>n;
        int nn=stoi(n);
        if (nn==0){
            cout<<"NULL";
        } else{
            if(nn%2==0){
                cout<<"EVEN ";
            } else{
                cout<<"ODD ";
            };
            if(nn<0){
                cout<<"NEGATIVE";
            } else{
                cout<<"POSITIVE";
            };
        };
        cout<<"\n";
    }
    return 0;
}