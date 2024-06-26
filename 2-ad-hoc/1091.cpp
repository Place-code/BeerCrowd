#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int x;
    cin>>x;
    while(x!=0){
        int cor_n[2][2];
        cin>>cor_n[0][0]>>cor_n[0][1];
        for(int i=0;i<x;i++){
            cin>>cor_n[1][0]>>cor_n[1][1];
            if(cor_n[0][0]==cor_n[1][0]|cor_n[0][1]==cor_n[1][1]){
                cout<<"divisa"<<endl;
            } else{
                int x=cor_n[1][0]-cor_n[0][0],y=cor_n[1][1]-cor_n[0][1];
                string xy="";
                if(y>0){
                    xy+="N";
                } else{
                    xy+="S";
                }
                if(x>0){
                    xy+="E";
                } else{
                    xy+="O";
                }
                cout<<xy<<endl;
            }
        }
        x=0;
        cin>>x;
    }
}