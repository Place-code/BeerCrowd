#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

int main(){
    while(true){
        char *split;
        int v[2];
        string n[2],pp;
        getline(cin,pp);
        split=strtok(&pp[0]," ");
        if(split==NULL){
            break;
        } else{
            for(int i=0;i<2;i++){
                v[i]=stold(split);
                split=strtok(NULL," ");
            }
        }
        for(int i=0;i<2;i++){
            string ponte;
            for(int j=0;j<32;j++){
                ponte+=to_string(v[i]%2);
                v[i]=int(v[i]/2);
                if(v[i]<1){
                    break;
                }
            }
            n[i]+=ponte;
        }
        int vv=1,ind_1=0,ind_2=0;
        float tot=0;
        while(ind_1<n[0].length()&&ind_2<n[1].length()){
            if(n[0][ind_1]-'0'+n[1][ind_2]-'0'==1){
                tot+=vv;
            }
            ++ind_2;
            ++ind_1;
            vv*=2;
        }
        if(ind_1<n[0].length()){
            for(int j=ind_1;j<n[0].length();j++){
                if(n[0][j]-'0'==1){
                    tot+=vv;
                }
                vv*=2;
            }
        } else if(ind_2<n[1].length()){
            for(int j=ind_2;j<n[1].length();j++){
                if(n[1][j]-'0'==1){
                    tot+=vv;
                }
                vv*=2;
            }
        }
        cout<<tot<<endl;
    }
    return 0;
}