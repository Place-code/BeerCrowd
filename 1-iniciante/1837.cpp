#include <iostream>
#include <cstring>
using namespace std;
using std::cout;

int main(){
    string str_n;
    int n[2],quo,r;
    getline(cin,str_n);
    char*split=strtok(&str_n[0]," ");
    for(int i=0;i<2;i++){
        n[i]=stoi(split);
        split=strtok(NULL," ");
    }
    quo=int(n[0]/n[1]);
    r=n[0]%n[1];
    if(r<0&&n[1]>0){
        r+=n[1];
        quo-=1;
    } else if(r<0&&n[1]<0){
        r-=n[1];
        quo+=1;
    }
    cout<<quo<<" "<<r<<endl;
}