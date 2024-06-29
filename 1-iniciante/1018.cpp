#include <iostream>
#include <vector>
#include<stdio.h>
using namespace std;
// 
int main()
{
    int cre;
    cin>>cre;
    cout<<cre<<endl;
    auto decompor=[cre]()->vector<int>{
        vector<int>deco={0,0,0,0,0,0,0}, var={100,50,20,10,5,2,1,0};
        int trem=cre;
        for(int i=0;i<7;i++){
            for(int j=i+1;j<8;j++){
                if(trem>=var[i]-var[j]){
                    deco[i]=1*int(trem/var[i]);
                    trem-=var[i]*int(trem/var[i]);
                    break;
                }
            }
            cout<<deco[i]<<" nota(s) de R$ "<<var[i]<<".00"<<endl;
        }
        return deco;
    };
    auto x=decompor();
    return 0;
}