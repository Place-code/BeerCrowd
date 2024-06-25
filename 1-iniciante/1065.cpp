#include <iostream>
using namespace std;

int main(){
    int pp=0;
    for(int i=0;i<5;i++){
        char ns[100];
        cin>>ns;
        if(stoi(ns)%2==0){
            ++pp;
        }
    }
    cout<<pp<<" valores pares";
}