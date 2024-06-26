#include <iostream>
#include <cstring>
#include <map>
using namespace std;
// 
int main()
{
    int r;
    cin>>r;
    cin.clear();
    cin.ignore(2147483647,'\n');
    for(int i=0;i<r;i++){
        string *c = new string[3], coisas="";
        map<char, int> analse;
        bool cheater=false;
        for(int j=0;j<3;j++){
            getline(cin,c[j]);
            if(j==0){
                for(int k=0;k<c[0].size();k++){
                    analse[c[0][k]]=-1;
                }
                analse['a']=-2;
            } else{
                c[j]+='a';
            }
        }
        // for(auto j:analse){
        //     cout<< j.first<<" "<<j.second<<endl;
        // }
        for(int j=1;j<3;j++){
            for(int k=0;k<c[j].size();k++){
                if(analse.find(c[j][k])!=analse.end()){
                    analse[c[j][k]]+=1;
                } else{
                    cheater=true;
                }
            }
        }
        int e=0;
        if(analse.find(2)!=analse.end()|cheater==true){
            cout<<"CHEATER";
        } else{
            string alfa;
            char trem;
            for(auto j:analse){
                if(j.second == -1){
                    alfa+=j.first;
                }
            }
            for(int j=0;j<alfa.length();j++){
                for(int k=0;k<j+1;k++){
                    if(alfa[k]>alfa[j]){
                        trem=alfa[j];
                        alfa[j]=alfa[k];
                        alfa[k]=trem;
                    }
                }
            }
            for(int j=0;j<alfa.length();j++){
                cout<<alfa[j];
            }
        }
        cout<<"\n";
        c=NULL;
        delete c;
    }
    return 0;
}